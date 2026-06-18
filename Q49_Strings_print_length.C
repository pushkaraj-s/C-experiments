#include <stdio.h>

int main(){
    
    //Write a program that inputs user's name and prints it's length.
    char fullName[100];
    
    printf("Enter full name: ");
    //scanf("%s", fullName);
    fgets(fullName, 100, stdin);
    
    int count = 0;
    for(int i=0; fullName[i] != '\0'; i++){
        count++;
    }
    printf("Length of character array is: %d\n", count-1);
    
    return 0;

}
