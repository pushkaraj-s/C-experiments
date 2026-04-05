#include <stdio.h>

//Write a funtion that prints Namaste if user is Indian
// And Bonjour is user is French
// We will ask user to enter either 'i' or 'f' to identify nationality 

void namaste();
void bonjour();

int main(){

    char c;
    printf("Enter a character 'i' or 'f': ");
    scanf("%c", &c);

    if(c == 'i' || c == 'I'){
        namaste();
    } else if(c == 'f' || c == 'F'){
        bonjour();
    } else{
        printf("Invalid Character \n");
    }

    /*
    
    Easy way to write this
    if(c == 'i'){
        namaste();    
    } else {
        bonjour();
    }
    
    
    */
    
    return 0;
}

void namaste(){
    printf("Namaste \n");
}

void bonjour(){
    printf("Bonjour \n");
}
