#include<stdio.h>

int main()
{   
    // We will practive bit manipulation here:
    unsigned char reg = 0b00001100;
    
    /***
     1) Suppose you have an 8-bit hardware register 
     represented as unsigned char reg = 0b00001100;
     How would you write a line of C code to set Bit 0 
     (the rightmost bit) to 1 without changing any of the other bits?
     Ans:
    ***/
    
     reg |= (1u << 0);
    
    /***
    2) Clear Bit 5 (force it to 0) using status_reg, the ~ operator, and <<.
    
    unsigned char status_reg = 0b10110100; 
    Bits are numbered 7 down to 0 from left to right:
    Bit 7 is '1', Bit 6 is '0', Bit 5 is '1', etc.
    Ans:
    ***/
    unsigned char status_reg = 0b00001100;
    status_reg &= ~(1u << 5);

    /***
    3) Check if Bit 4 is set to 1. Write an if statement condition that evaluates to 
        true if Bit 4 is a 1, and false if it is a 0.
    Ans:
    ***/ 
    
    if(status_reg & (1u << 4)){
        return 1;
    } else {
        return 0;
    }
    
  
    
    return 0;
}
