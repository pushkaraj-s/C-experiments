#include <stdio.h>

int main(){
    //Write a program to input student information from a user & enter it to a file
    FILE *fptr;
    fptr = fopen("student.txt", "w");
    
    char name[50];
    int age;
    float cgpa;
    
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter CGPA: ");
    scanf("%f", &cgpa);
    
    fprintf(fptr, "Student Name: %s\n", name);
    fprintf(fptr, "Student Age: %d\t", age);
    fprintf(fptr, "Student CGPA: %f\t", cgpa);
    
    fclose(fptr);
    return 0;
}
