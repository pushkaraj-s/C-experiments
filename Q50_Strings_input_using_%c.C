#include <stdio.h>

int main(){
    
    //Take string inute from user using %c
    char str[100];
    char ch;
    int i = 1;

    printf("Enter a string: ");
    scanf("%c", str);
    
    while(ch != '\n'){
        scanf("%c", &ch);
        str[i] = ch;
        i++;
    }
    
    str[i] = '\0'; //Need to manually add null character
    puts(str);
    
    return 0;

}
