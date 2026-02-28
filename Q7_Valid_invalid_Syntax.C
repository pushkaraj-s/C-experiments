#include <stdio.h>

int main(){

    1) int a = 8^8        -> Valid //However this will not give output as 8 raised 8, for that use pow(x,y)

    2) int x; int y = x;  -> Valid // syntax wise correct, as int x and int y = x are 2 different lines

    3) int x,y = x;       -> invalid // Variable declared and used in same line

    4) char stars = '**'  -> invalid // Only one char is allowed to store in char data type, even space after first * will give error.

return 0;
}