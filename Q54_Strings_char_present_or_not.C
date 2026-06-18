#include <stdio.h>

void checkChar(char str[], char ch);

int main(){

    //Check if a given character is present in a string or not
    
    char str[] = "Pushkaraj";
    char ch = 'k';
    checkChar(str, ch);

    return 0;
}

void checkChar(char str[], char ch){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == ch){
            printf("Character is present in the string.\n");
            return;
            break;
        }
    }
    printf("Character is not present in the string.\n");
}