#include <stdio.h>

//Print "Hello World" 5 times using Recusrion

void printHello(int count);

int main(){

    printHello(5);

    return 0;
}

//recursive funtion
void printHello(int count){
    if (count == 0){
        return;
    }    
    printf("Hello World \n");
    printHello(count-1);
}    