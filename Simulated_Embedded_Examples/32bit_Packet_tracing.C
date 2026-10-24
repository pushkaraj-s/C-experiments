#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
 * ============================================================================
 *                         32-BIT PACKET SPECIFICATION
 * ============================================================================
 *
 *  Bit(s)   | Field Name       | Mask     | Description
 *  ---------|------------------|----------|----------------------------------
 *  30 - 31  | Message ID       | 0x     | Uniquely identifies the message stream
 *  27 - 29  | Number of packets| 0x     | Total packets expected in this stream
 *  24 - 26  | Sequence number  | 0x     | Order index of the current packet
 *  20 - 23  | Permissions      | 0x     | File access permission bitmask
 *   4 - 19  | Filename segment | 0x     | 2 ASCII bytes containing characters
 *   0 -  3  | Error code       | 0x     | Protocol error status (0 = Success)
 *
 *  Visual Memory Map (32-bit layout):
 *  [31 30] [29 28 27] [26 25 24] [23 22 21 20] [19 ... 4] [3 2 1 0]
 *  | MsgID| |Num Pack| |Seq Num | |Permissions| | Filename | |ErrCode|
 * ============================================================================
 */

// Parse this packets to decode the actual data inside it
// Trace the incoming packets store fileName in char array
// Pass this char array with permission variable to create a file.

// [31 30] [29 28 27] [26 25 24] [23 22 21 20] [19 ... 4] [3 2 1 0]
//   0  0    0  1  0    0  0  0   0  0   0  1   4 E  6 5   0 0 0 0 
//   0  0    0  1  0    0  0  1   0  0   0  1   7 7  0 0   0 0 0 0 

#define MAX_PACKETS 8 //3-bits in Num Pack can represent max 8 values
#define MAX_LETTERS 16 // Each packet has 2 letter, including NULL at end I can receive max 16 chars

// Mock declration of system hook provided by CoderPad
void create_file(const char* Filename, uint8_t permissions);

// --- Stateful Receiver Architecture ---
typedef struct{
    uint8_t expected_msg_id;
    uint8_t total_packets;
    uint8_t permissions;
    uint8_t packets_received_count;
    bool is_active_session;
    
    // Tracks slot fulfillment to hande out-oforder deliveries safely
    bool slot_filled[MAX_PACKETS];
    // Storage buffer for reconstructed characters
    char filename_buffer[MAX_LETTERS];
} ReceiverState;

// Global context tracker
static ReceiverState state = {0};

static void reset_receiver_state(void){
    memset(&state, 0, sizeof(ReceiverState));
}

// --- Core entry point called one-at-a-time packet arrives

bool process_Packet(uint32_t packet){
    // 1. Bit manipulation to extract each section of a single packet
    
    uint8_t msg_id        = (uint8_t)((packet >> 30) & 0x3u);
    uint8_t num_packets   = (uint8_t)((packet >> 27) & 0x7u);
    uint8_t seq_num       = (uint8_t)((packet >> 24) & 0x7u);
    uint8_t permissions   = (uint8_t)((packet >> 20) & 0xFu);
    uint16_t filename_seg = (uint16_t)((packet >> 4) & 0xFFFFu);
    uint8_t error_code    = (uint8_t)(packet & 0xFu);
    
    
    // 2. Error verification
    if(error_code != 0){
        // Drop bad frame; Systems choice to reset tracking state or ignore
        return false;
    }
    
    // 3. Lifecycle Initialization & Stream Validation
    if(seq_num == 0){
        reset_receiver_state();
        state.expected_msg_id = msg_id;
        state.total_packets = num_packets;
        state.permissions = permissions;
        state.is_active_session = true;
    } else {
        // Validate context to confirm frame belongs to active sequence
        if(!state.is_active_session || msg_id != state.expected_msg_id){
            return false; // Packet drop
        }
    }
    
    // 4. Fragment placement & Re-assembly
    //Process segment if this packet slot has not already been filled (avoid duplicates)
    if(!state.slot_filled[seq_num]){
        // Extract 2 ASCII chars from 16-bit segment
        char char1 = (char)((filename_seg >> 8) & 0xFFu);
        char char2 = (char)(filename_seg & 0xFFu);
        
        // Put pieces into exact position boundries (2 bytes per sequence interval)
        state.filename_buffer[seq_num * 2] = char1;
        state.filename_buffer[(seq_num * 2) + 1] = char2;
        
        state.slot_filled[seq_num] = true;
        state.packets_received_count++;
    }
    
    // 5. Final Assembly and Hook Execution trigger
    if(state.packets_received_count == state.total_packets){
        // Terminate string formatting to filter remaining padding safely
        
        // Calculate max bound filled based on total packets execute
        int max_possible_len = state.total_packets * 2;
        if(max_possible_len >= MAX_LETTERS){
            max_possible_len = MAX_LETTERS -1;
        }
        
        // Add string termination
        state.filename_buffer[max_possible_len] = '\0';
        
        // Pass complete tracking dataset forward to target OS handler
        create_file(state.filename_buffer, state.permissions);
        
        // Terminate contect lifecycle tracker cleanly
        reset_receiver_state();
    }


bool CreateFile(char* filename, bool permission){
    if(permission == 1){
        printf("File %s is created", filename);
        return true;
    } else if(permission == 0){
        printf("File creation permission Denied!");
        return false;
    } else {
        printf("Error occurred!");
    }
    return false;
}

int main(){
    
    bool valid = process_Packet(packet);
    if(valid == false){
        return -1;
    }
    
    return 0;
}

