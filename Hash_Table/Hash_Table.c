// Implementing Hash Table in C
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct{
    char name[MAX_NAME];
    int age;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i=0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table(){
    for(int i=0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    // Table is empty
}

void print_table(){
    for (int i=0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hash_table_insert(person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL){
        return false;
    }
    hash_table[index] = p;
    return true;
}

int main(){
    
    init_hash_table();
    print_table();
    
    
    person jacob = {.name="Jacob", .age= 26};
    person kate = {.name="Kate", .age= 27};
    person mpho = {.name="Mpho", .age= 22};
    person raj = {.name="Raj", .age= 31};
    
    
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&raj);
    
    /***
    printf("Jacob => %u\n", hash("Jacob"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Tebogo => %u\n", hash("Tebogo"));
    printf("Raj => %u\n", hash("Raj"));
    ***/
    
    return 0;
}