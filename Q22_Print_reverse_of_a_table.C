#include <stdio.h>

//Print reverse of the table for number from user

int main(){
    
    int n;
    printf("Enter a Number: ");
    scanf("%d", &n);
    
    for(int i=10; i>=1 ;i--){
        printf("%d \n", n*i);
    }


    return 0;
}