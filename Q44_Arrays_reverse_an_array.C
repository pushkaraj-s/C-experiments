
// There are multiple ways to reverse an array in C. Here are a few common approaches:
// 1. Using a temporary array
// 2. Swapping elements from both ends (We can start by exchanging ends of an array and travl towards mid point)
// 3. Using recursion

//We will implement the first approach: Using a temporary array.
#include <stdio.h>

void reverse(int arr[], int n);
void printArr(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    printArr(arr, 5);

    return 0;
}

void reverse(int arr[], int n) {
    for (int i = 0; i < n/2; i++) {
        int firstVal = arr[i];
        int secondVal = arr[n - 1 - i]; //Understand this line we are swapping the elements from the start and end of the array.
        arr[i] = secondVal;
        arr[n - 1 - i] = firstVal;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
