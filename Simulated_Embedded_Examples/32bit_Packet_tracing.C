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
void create_file9const char* Filename, uint8_t permissions);

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
    memset(&state, 0, sozepf(ReceiverState));
}

// --- Core entry point called one-at-a-time packet arrives

void process_Packet(uint32_t packet){
    // Bit manipulation to extract each section of a single packet
    
    uint8_t msg_id        = (uint8_t)((packet >> 30) & 0x3u);
    uint8_t num_packets   = (uint8_t)((packet >> 27) & 0x7u);
    uint8_t seq_num       = (uint8_t)((packet >> 24) & 0x7u);
    uint8_t permissions   = (uint8_t)((packet >> 20) & 0xFu);
    uint16_t filename_seg = (uint16_t)((packet >> 4) & 0xFFFFu);
    uint8_t error_code    = (uint8_t)(packet & 0xFu);
    
    
    // Error verification
    if(error_code != 0){
        // Drop bad frame; Systems choice to reset tracking state or ignore
        return false;
    }
    
    // Lifecycle Initialization & Stream Validation
    if(seq_num == 0){
        reset_receiver_state();
        state.expected_msg_id = msg_id;
        state.total_packets = num_packets;
        state.permissions = permissions;
        state.is_active_session = true;
    } else {
        // Validate context to confirm frame belongs to active sequence
        if(!state.is_active_session || msg_id != state.expected_msg_id){
            return; // Packet drop
        }
    }
    
    size_t count = m1.numPack;
    
    fileName[0] = (m1.data >> 8) & 0xFF; 
    fileName[1] = (m1.data) & 0xFF;
    
    for(size_t i=0; i < count-1; i++){
        message m[i];
        //Parse all letters one by one
        uint16_t letter = (uint16_t)(packet >> 4) & 0xFFFFu;
        
        fileName[i] = letter;
    }
    
}




bool CreateFile(bool permission, char* fileName){
    if(permission == 1){
        printf("File "%s" is created, fileName);
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
    
    bool valid = parsePacket(packet);
    if(valid == flase){
        return -1;
    }
    
    CreateFile();
    
    return 0;
}

