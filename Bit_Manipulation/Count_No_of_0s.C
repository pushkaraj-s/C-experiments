#include<stdio.h>

int main()
{
    unsigned char reg = 0x8C; //0b 1000 1100;
    int count = 0;
    
    // Count no of 0s
    for(int i=0; i < 8; i++){
        if(~(reg >> i) & (0x01u)){
            count++;
        }
    }
    
    printf("No of 0's are: %d\n", count);
  
    
    return 0;
}
