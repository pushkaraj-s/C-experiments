#include <stdio.h>

int main(){
    int x; //'%'(Mod) is only valid for int data type, making variable float will give us error
    printf("Enter a number = ");
    scanf("%d", &x);
    
    if(x%2 == 0){
        printf("Number is divisible by 2");
    }
    else{
        printf("Number is not divisible by 2");
    }

return 0;
}