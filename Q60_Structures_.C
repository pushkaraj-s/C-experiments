#include <stdio.h>

typedef struct bankAccount{
    char name[50];
    int accountNo;
 } acc;
 
int main(){
    
    // Make a struct to store Bank account info of a customer of ABC Bank
    // Also make an alias for it
    
    acc acc1 = {"Pushkaraj", 123};
    acc acc2 = {"Pushkar", 124};
    acc acc3 = {"Raj", 125};
    
    printf("Name: %s\n", acc1.name);
    printf("Account no: %d\n\n", acc1.accountNo);

    printf("Name: %s\n", acc2.name);
    printf("Account no: %d\n\n", acc2.accountNo);

    printf("Name: %s\n", acc3.name);
    printf("Account no: %d\n\n", acc3.accountNo);
    
    return  0;
}
