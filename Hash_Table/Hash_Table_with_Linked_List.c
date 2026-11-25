// Implementing Hash Table in C
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFUL)

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
    printf("Start\n");
    for (int i=0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("END\n\n");
}

bool hash_table_insert(person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    for (int i=0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL || hash_table[try] == DELETED_NODE){
            hash_table[try] = p;
            return true;
        }
    }
   
    return false;
}

// Find person in the table by their name
person* hash_table_lookup (char *name){
    int index = hash(name);
    for (int i=0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return false; // Not here
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(strcmp(hash_table[try]->name, name) == 0){
        return hash_table[try];
        }
    }
    
    return NULL;
}

person* hash_table_delete(char *name){
    int index = hash(name);
    for (int i=0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return NULL; // Not here
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(strcmp(hash_table[try]->name, name) == 0){
        person* tmp = hash_table[try];
        hash_table[try] = DELETED_NODE;
        return tmp;
        }
    }
    
    return NULL;
}

int main(){
    
    init_hash_table();
    print_table();
    
    
    person jacob = {.name="Jacob", .age= 26};
    person kate = {.name="Kate", .age= 27};
    person mpho = {.name="Mpho", .age= 22};
    person raj = {.name="Raj", .age= 31};
    person sarah = {.name="Sarah", .age= 16};
    person robert = {.name="Robert", .age= 45};
    person eliza = {.name="Eliza", .age= 52};
    person edna = {.name="Edna", .age= 11};
    
    
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&raj);
    hash_table_insert(&sarah);
    hash_table_insert(&robert);
    hash_table_insert(&eliza);
    hash_table_insert(&edna);
    print_table();
    
    person* tmp = hash_table_lookup("Mpho");
    
    if(tmp == NULL){
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }
    
    hash_table_delete("Mpho");
    print_table();
    
    hash_table_delete("Raj");
    print_table();
    
    /***
    printf("Jacob => %u\n", hash("Jacob"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Tebogo => %u\n", hash("Tebogo"));
    printf("Raj => %u\n", hash("Raj"));
    ***/
    
    return 0;
}