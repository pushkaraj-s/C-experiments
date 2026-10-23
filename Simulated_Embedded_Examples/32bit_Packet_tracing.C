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

#define MAX_MESSAGE_PACKETS 8 //3-bits in Num Pack can represent max 8 values
#define MAX_LETTERS 16 // Each packet has 2 letter, including NULL at end I can receive max 16 chars

typedef struct{
    uint8_t msgID;
    uint8_t numPack;
    uint8_t seqNum;
    uint8_t permission;
    uint8_t errCode;
    uint16_t data;
} message;

char fileName[MAX_LETTERS];

uint32_t packet = 0x00200E650; // Example packet to be parsed

bool parsePacket(uint32_t packet){
    // Bit manipulation to extract each section of a single packet
    
    message m1;
    m1.msgID      = (uint8_t)(packet >> 30) & 0x3u; // msgID: 0000 & 0011 = 0000
    m1.numPack    = (uint8_t)(packet >> 27) & 0x7u; // numPack: 0000 & 0111 = 0000
    m1.seqNum     = (uint8_t)(packet >> 24) & 0x7u;
    m1.permission = (uint8_t)(packet >> 20) & 0xFu;
    m1.data       = (uint16_t)(packet >> 4) & 0xFFFFu; // (0010 1110 0110 0101) & (1111 1111 1111 1111)
    m1.errCode    = (uint8_t)packet & 0xFFu;
    
    // Error verification
    if(m1->errCode != 0){
        return false;
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

