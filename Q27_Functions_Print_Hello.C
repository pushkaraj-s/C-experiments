#include <stdio.h>

//Write 2 Functions - one to print "Hello World"
// And other to print "Goodbye"

void printHello(); //Declaration 
void printGoodbye();

int main(){

    printHello(); //Function Call
    printGoodbye();

    return 0;
}

void printHello(){ //Funtion Definition
    printf("Hello World \n");
}

void printGoodbye(){
    printf("Goodbye :) \n");
}