#include <stdio.h>

int main(){

    // Write a Program to find if a character entre by user
    // is upper case or not

    char Character;
    printf("Enter a Character = ");
    scanf("%c", &Character);


    // Ch >=97 and Ch >= 'a' Both these conditions are same for compiler.
    // By 97 is the ASCII value of a that is why writting 'a' or 'z'
    // gives us desired outputs.

    if(Character >= 'a' && Character <= 'z'){
        printf("Charater is Lower case \n");
    } 
    else if(Character >= 'A' && Character <= 'Z'){
        printf("Charater is Upper Case \n");
    }
    else{
        printf("Not English Letter \n");
    }

    return 0;
}