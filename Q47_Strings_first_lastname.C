#include <stdio.h>

void printString(char arr[]);

int main(){
    
    //Create a string firstName and lastName to store details of user and print all the char using a loop.
    
    char firstName[] = "Pushkaraj";
    char lastName[] = "Said";
    
    printString(firstName); //Here we are not passing array size 
    printString(lastName); //as null character will be checked for end of the array.    
    return 0;
}

void printString(char arr[]){
    for(int i=0; arr[i] != '\0'; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
}
