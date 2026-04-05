#include <stdio.h>

//Write a function to calculate area of a square, circle and a rectangle.

float squareArea(int);
float circleArea(int);
float rectangleArea(int, int);


int main(){

    int squareSide, circleRadious, rectangleSide1, rectangleSide2;
    printf("Enter side of Square: ");
    scanf("%d", &squareSide);

    printf("Enter radious of Circle: ");
    scanf("%d", &circleRadious);

    printf("Enter side1 for Rectangle: ");
    scanf("%d", &rectangleSide1);

    printf("Enter side2 for Rectangle: ");
    scanf("%d", &rectangleSide2);

    printf("Area of Square: %f \n", squareArea(squareSide));
    printf("Area of Circle: %f \n", circleArea(circleRadious));
    printf("Area of Rectangle: %f \n", rectangleArea(rectangleSide1, rectangleSide2));
    return 0;
}

float squareArea(int s){
    int area;
    area = s*s;
    return area;

    //Can be optimized like (reduce variables and lines of code)
    //return s*s; (Just one line of code)
}

float circleArea(int r){
    int area;
    area = 3.14*r*r;
    return area;
}

float rectangleArea(int s1, int s2){
    int area;
    area = s1*s2;
    return area;
}

