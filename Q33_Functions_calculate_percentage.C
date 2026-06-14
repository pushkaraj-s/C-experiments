#include <stdio.h>

int calcPercentage(int science, int math, int sanskrit);

int main() {
    int science = 85;
    int math = 90;
    int sanskrit = 75;
    int percentage = calcPercentage(science, math, sanskrit);
    printf("Percentage: %d\n", percentage);
    return 0;
}

int calcPercentage(int science, int math, int sanskrit) {
    int total = science + math + sanskrit;
    return (total * 100) / 300;
}