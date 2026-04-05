#include <stdio.h>

/*
In these examples we will understand how Arithmatic operation are performed,
According to their 'Operator precedace'

If you observe closely general BODMAS rules are applied here.

Priority: 1) * , / , %
          2) = , -
          3) =


Associativity rule: If operator precendance is same, calculate from left to right -->
*/
int main(){

//Now acording to precedence order mention above, identify values of these math expressions
int a = 5 * 2 - 2 * 3;

int b = 5 * 2 / 2 * 3;

int c = 5 * (2 / 2) * 3;

int d = 5 + 2 / 2 * 3;

printf("Values are \n a = %d \n b = %d \n c = %d \n d = %d \n", a,b,c,d);


return 0;
}
