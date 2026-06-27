#include <stdio.h>

int main(){
    //Write a program to write all odd numbers in a file.
   
   int m,n = 0;
   printf("Enter number N = ");
   scanf("%d", &m);
   printf("Enter number M = ");
   scanf("%d", &n);
   
   FILE *fptr;
   fptr = fopen("text.txt", "w");
   
   for(int i=m; i <= n; i++ ){
    if(i%2 == 1){
        fprintf(fptr, "%d\t", i);
    }
   }
     
    return 0;
}