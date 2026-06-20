#include <stdio.h>
#include <string.h>

 typedef struct address{
    int house_no;
    int block_no;
    char city[50];
    char state[50];
 } add ;
 
 void printInfo(add temp);
 
 int main(){

   //Write a program to store and print address of 5 people using structures
    
    add a1 = {123, 5524, "Fremont", "California"};
    add a2 = {345, 3928, "Santa clara", "California"};
    add a3 = {278, 2315, "San jose", "California"};
    add a4 = {232, 1194, "Sunnyvale", "California"};
    add a5 = {178, 3582, "College station", "Texas"};

    //Or we can use Array of structs here, 
    //struct address adds[5];

    printInfo(a1);

    //Concepts leanred:
    // How to define struct
    // Use struct in a function
    // How to make struct array
    
    return 0;
 }
 
 void printInfo(add temp){
    printf("Address is: House %d, block no %d, %s, %s\n", temp.house_no, temp.block_no, temp.city, temp.state);
    printf("\n");
}
