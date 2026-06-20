#include <stdio.h>

 struct complex{
    int real;
    int imaginary;
 };
 
 int main(){
    
    //Create a structure to store complex numbers (use arrow operator).
    //Complex numers have some real part and some imaginary part to them.
    
    struct complex number1 = {5, 8};
    struct complex *ptr = &number1;

    printf("Imaginary part= %d \nReal Part= %d\n", ptr->imaginary, ptr->real);
    
    return 0;
 }
