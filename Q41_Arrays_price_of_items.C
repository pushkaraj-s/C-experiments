#include <stdio.h>

int main(){
    
    //Write a program to enter price of 3 items and print their final cost with gst
    //3 items ----> float + 18% gst
        
    float price[3];
    printf("Enter 3 prices: \n");
    
    printf("Prices 1: ");
    scanf("%f", &price[0]);

    printf("Prices 2: ");
    scanf("%f", &price[1]);

    printf("Prices 3: ");
    scanf("%f", &price[2]);
    
    printf("\nTotal price 1: %f\n", price[0]+(0.18*price[0]));
    printf("Total price 2: %f\n", price[0]+(0.18*price[1]));
    printf("Total price 3: %f\n", price[0]+(0.18*price[2]));
   
    return 0;
}
