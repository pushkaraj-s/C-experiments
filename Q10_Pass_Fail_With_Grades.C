#include <stdio.h>

int main(){

    //Write a Program to give grades to a student
    //marks < 30 is C
    //30 <= marks < 70 is B
    //70 <= marks < 90 is A
    //90 <= marks <= 100 is A+

    int marks = 0;
    printf("Enter Marks = ");
    scanf("%d", &marks);

    if(marks >= 0 && marks < 30){
        printf("Grade is C \n");
    } 
    else if(marks >= 30 && marks < 70){
        printf("Grade is B \n");
    } 
    else if(marks >= 70 && marks < 90){
        printf("Grade is A \n");
    } 
    else if(marks >= 90 && marks < 100){
        printf("Grade is A+ \n");
    } 
    else {
        printf("Invalid Grades \n");
    }

    return 0;
}