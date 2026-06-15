#include <stdio.h>

void printAddress(int n);

int main(){
    
    //Will the address output be same?
    //We have same variable n in main() and printAdress() function, will this print same address for n?
    //For this we need to understand "pass by value" and "pass by reference" concepts
    
   int n = 4;
   printf("%p \n", &n);
   printAddress(n);
    
    return 0;
}

void printAddress(int n){
    printf("%p \n", &n);
}
