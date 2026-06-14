#include <stdio.h>

//Write a function to convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius);

int main(){
    float celsius = 0;
    float fahrenheit = celsius_to_fahrenheit(celsius);
    printf("Celsius: %f, Fahrenheit: %f\n", celsius, fahrenheit);
    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}
