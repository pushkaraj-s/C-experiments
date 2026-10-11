#include <stdio.h>
#include <stdbool.h>

//Implementing circular queue
//Has fixed capacity, fifo style access
//push, pop, front, empty
//We can use array and use it's capacity
//Use 2 pointers, front and read pointer
//Also track currSize
//Initialize front with Zero and rear with -1
//fixed array, dynamic array, linked list

int f = 0, r = -1;
const int capacity = 5;
int arr[5];
int currSize = 0;

void push(int data){
  if(currSize == capacity){
    printf("Circular Queue is FULL!");
    return;
  }

  r = (r+1) % capacity;
  arr[r] = data;
  currSize++;
}

void pop(){
  if(currSize == 0){
    printf("Circular Queue is EMPTY!");
    return;
  }

  f = (f+1) % capacity;
  currSize--;
}

int front(){
  return arr[f];
}

void print_CQ(){
  if(currSize == 0){
    printf("Circular Queue is EMPTY!");
    return;
  }

  int tempSize = currSize;
  int i = f-1;
  while(tempSize){
    i = (i+1) % capacity;
    printf("%d ", arr[i]);
    tempSize--;
  }
  printf("\n");

  return;
}

bool empty(){
  return currSize ==0;

}



int main(){
  //int arr[capacity];

  push(1);
  push(2);
  push(3);
  push(4);

  pop();

  print_CQ();


  return 0;
}