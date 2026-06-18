#include <stdio.h>

int main(){
    
    //a) Ask user to enter their first name and print it back to them.
    //Also try this with their FullName.
    char fullName[100];
    
    printf("Enter Full name: ");
    scanf("%s", fullName); //Notice here we are not passing &fullName to scanf. For arrays use their name without &
    printf("Your Full name is: %s \n", fullName); //fullName is a character array and we are passing its name (which is a pointer to the first element) to printf.

    //Here we can use gets() and puts() functions as well.
    //gets() is now getting deprecated, so it's better to use fgets() instead.
    //puts() is used to print a string followed by a newline.
    
    return 0;

}
