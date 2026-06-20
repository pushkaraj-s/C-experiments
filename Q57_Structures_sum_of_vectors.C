#include <stdio.h>

struct vector{
   int x;
   int y;
};
 
void calculateSum(struct vector v1, struct vector v2, struct vector *sum);
 
int main(){
    
   //Create a structure to store vectors. Then make a function to return sum of 2 vectors.
    
   struct vector v1 = {5, 10};
   struct vector v2 = {3, 7};
   struct vector sum = {0, 0};
   calculateSum(v1, v2, &sum); //Passing sum using pointer.
   
   printf("Sum x= %d \nSum y= %d\n", (sum).x, (sum).y);
    
   return 0;
}
 
void calculateSum(struct vector v1, struct vector v2, struct vector *sum){
   (*sum).x = v1.x + v2.x;
   (*sum).y = v2.y + v2.y;
}
