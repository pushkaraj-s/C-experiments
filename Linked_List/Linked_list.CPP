#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
    
public:
    List(){
        head = tail = NULL;
    }
    
    void push_front(int val){ //Time complex: O(1)
        Node* newNode = new Node(val); //Dynamic object
        if(head == NULL){
            //printf("List is Empty\n");
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
        
    }
    
    void push_back(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void pop_front(){
        if(head == NULL){
            printf("Empty Linked List");
            return;
        }
        
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
    }
    
    void pop_back(){
        if(head == NULL){
            printf("Empty Linked List");
            return;
        }
        
        Node* temp = head;
        while((temp->next) != tail){
            temp = temp->next;
        }
        
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    void insert(int val, int pos){
        if(pos < 0){
            printf("Invalid Position");
            return;
        }
        
        if(pos == 0){
            push_front(val);
            return;
        }
        
        Node* temp = head;
        for(int i=0; i < pos-1; i++){
            if(temp == NULL){
                printf("Invalid Position");
                return;
            }
            temp = temp->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    int search(int key){
        Node* temp = head;
        int idx = 0;
        
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            
            temp = temp->next;
            idx++;
        }
        
        return -1;
    }
    
    void printLL(){
        Node* temp = head;
        
        while(temp != NULL){
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    
};

int main(){
    List ll;
    
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.printLL();
    
    ll.push_back(4);
    ll.printLL();
    
    ll.insert(4, 0);
    ll.printLL();
    
    ll.pop_front();
    ll.printLL();
    
    cout << ll.search(2) << endl;
    
    return 0;
}