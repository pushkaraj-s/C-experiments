// Implementing Hash Table in C
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct{
    char name[MAX_NAME];
    int age;
} person;

unsigned int hash(char *name){
    return 5;
}

int main(){
    printf("Jacob => %u\n", hash("Jacob"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Tebogo => %u\n", hash("Tebogo"));
    printf("Raj => %u\n", hash("Raj"));
    
    return 0;
}