#include <stdio.h>
#include <string.h>

void salting(char pass[]);

int main(){

    //Salting is the process of adding a random string to a password before hashing it.
    //Concept used to secure our passwords in big companies, to avoid hacking.
    
    //Find the salted form of a password entered by user if the salt is "123" and added at the end.
    
    /*  
        Ex: Pass = "test123"
            salt = "abc"
            newPass = "test123abc"
    */    
    
    char pass[100];
    
    printf("Enter Password: ");
    scanf("%s", pass);
    salting(pass);
    
    return 0;
}

void salting(char pass[]){
    char salt[] = "123";
    char newPass[100];
    strcpy(newPass, pass); //newPass = "test"
    strcat(newPass, salt); // newPass = "test123"
    puts(newPass);
        
}