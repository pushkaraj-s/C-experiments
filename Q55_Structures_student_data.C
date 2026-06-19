
//Definition: A structure is a user-defined data type in C that allows you to group together variables of different data types under a single name.

/*
For a student store the following information:
#syntax: 

struct student {
    int id; 
    char name[50];
    float marks;

Use: 
struct student s1; 
s1.id = 1;
s1.marks = 85.5;   
strcpy(s1.name, "Pushkaraj");
*/

#include <stdio.h>
#include <string.h>

struct student{ 
    int roll;
    float cgpa;
    char name[50];
};

void printInfo(struct student temp);

int main(){

    //Write a program to store the data of 3 students
    struct student s1;
    s1.roll = 20;
    s1.cgpa = 9.3;
    strcpy(s1.name, "Pushkaraj");
    printInfo(s1);
    
    struct student s2;
    s2.roll = 21;
    s2.cgpa = 9.5;
    strcpy(s2.name, "Pushkar");
    printInfo(s2);
    
    struct student s3;
    s3.roll = 22;
    s3.cgpa = 8.9;
    strcpy(s3.name, "Raj");
    printInfo(s3);

    return 0;
}

void printInfo(struct student temp){
    printf("Name: %s\n", temp.name);
    printf("Roll Number: %d\n", temp.roll);
    printf("CGPA: %f\n", temp.cgpa);
    printf("\n");
}
