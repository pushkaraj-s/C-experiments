
// Implementing queue from scratch
// push(), pop(), print_front(), print_queue()
// push from rear, pop from front
// keep track of capacity of queue
#include<stdio.h>

#define SIZE 5

int queue[SIZE] = {0};
int rear = -1, front = -1;
int curr_capacity = 0;

// 1 2 3 4 5
// f       r

void push(int val){
    if(curr_capacity == SIZE){
        printf("Queue is FULL!\n");
        return;
    }
    
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
    curr_capacity++;
    
    if(curr_capacity == 1){
        front = 0;
    }
    
    return;
}

int pop(){
    if(curr_capacity == 0){
        printf("Queue is EMPTY!\n");
        return -1;
    }
    
    int temp = queue[front];
    queue[front] = 0;
    front = (front + 1) % SIZE;
    curr_capacity--;
    
    if(curr_capacity == 0){
        front = -1;
        rear = -1;
    }
    
    return temp;
}

void print_front(){
    if(curr_capacity == 0){
        printf("Queue is EMPTY!\n");
        return;
    }
    
    printf("Front of the queue = %d\n", queue[front]);
    
    return;
}

void print_queue(){
    int temp_curr = curr_capacity;
    int temp_front = front;
    while(temp_curr){
        printf("%d ", queue[temp_front]);
        temp_front = (temp_front + 1) % SIZE;
        temp_curr--;
    }
    
    printf("\n");
    
    return;
}


int main()
{
    printf("Welcome to Online IDE!! Happy Coding :)\n");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print_queue();
    push(6);
    
    print_front();
    print_queue();
    
    pop();
    print_front();
    
    pop();
    pop();
    pop();
    pop();
    pop();
    
    print_queue();
    
    //Checking if circular indexing works
    // This confirms that your queue can reuse freed array 
    // positions without disturbing FIFO order.
    
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    pop();
    pop();
    
    push(60);
    push(70);
    
    print_queue();
    
    return 0;
}

/*** 
Output:

Welcome to Online IDE!! Happy Coding :)
1 2 3 4 5 
Queue is FULL!
Front of the queue = 1
1 2 3 4 5 
Front of the queue = 2
Queue is EMPTY!

30 40 50 60 70 

***/