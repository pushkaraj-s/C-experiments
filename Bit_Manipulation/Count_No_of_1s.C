
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>

int main()
{
    printf("Welcome to Online IDE!! Happy Coding :)\n");
    
    // We will practive bit manipulation here:
    unsigned char reg = 0xCC; //0b11001100;
    int count = 0;
    
    // Count no of 1s
    for(int i=0; i < 8; i++){
        if((reg >> i) & 0x1u){
            count++;
        }
    }
    
    printf("No of 1's are: %d\n", count);
  
    
    return 0;
}
