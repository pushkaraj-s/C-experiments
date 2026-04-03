#include <stdio.h>

//Write a program to cehck if a student is failed or passed.

int main(){

    int marks = 0;

    printf("Enter marks (0-100) = ");
    scanf("%d", &marks);

    if(marks >= 0 && marks <= 30){
        printf("Fail\n");
    } else if(marks > 30 && marks <=100){
        printf("Pass\n");
    } else {
        printf("Invalid Marks");
    }

    //This entire code can be replaed by turnary operator like this:
    //  marks <= 30 ? printf("Fail\n") : printf("Pass\n");

    return 0;
}