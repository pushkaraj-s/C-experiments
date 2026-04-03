#include <stdio.h>

//Keep taking input from user and stop when odd number is input

int main(){

    int n = 0;
    while(n%2 == 0){
        printf("Enter a number: ");
        scanf("%d", &n);
    }

    printf("Odd number is entered \n");

    //Alternate method to solve, using break; statement
    /*
    int main() {
        int n;
        do {
            printf("enter number: ");
            scanf("%d", &n);
            printf("%d\n", n);
            if(n % 2 != 0) {
                break;
            }
        } while(1);

        printf("thank you");
        return 0;
    }

    */

    return 0;
}