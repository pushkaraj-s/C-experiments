#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* head = NULL;

void push_front(int val){
    if(head == NULL){
        printf("List is Empty!\n");
        return;
    }
    
    struct node* newNode = NULL;
    newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = val;
    newNode->link = head;
    head = newNode;
    
    return;
}

void push_back(int val){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    
    struct node* newNode = NULL;
    newNode = (struct node*)malloc(sizeof(struct node));
    
    struct node* ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    
    newNode->data = val;
    newNode->link = NULL;
    ptr->link = newNode;
    
    return;
}

void pop_front(){
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }
    
    struct node* ptr = head->link;

    free(head); //Critical step
    head = ptr;
}

void pop_back(){
  if(head == NULL){
    printf("Empty List\n");
    return;
  }

  struct node* ptr = head;
    while((ptr->link->link) != NULL){
        ptr = ptr->link;
    }

    free(ptr->link);
    ptr->link = NULL;
}

void count_nodes(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    
    int count = 0;
    
    struct node* ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    
    printf("Total Nodes = %d\n", count);
}

void print_ll(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    
    struct node* temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}



int main(){
    
    print_ll();
    
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    
    printf("%d\n", head->data);
    print_ll();
    
    push_front(44);
    print_ll();
    
    push_front(43);
    print_ll();
    
    push_front(42);
    print_ll();
    
    push_front(41);
    print_ll();
    
    push_back(46);
    print_ll();
    
    count_nodes();

    pop_front();
    print_ll();

    pop_back();
    print_ll();

    count_nodes();

    return 0;
}