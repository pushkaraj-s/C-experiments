#include <stdio.h>

void slice(char temp_arr[], int m, int n);

int main(){

    //Write a function named slice which takes a string and returns a sliced string from index n to m
    
    // Ex. "h e l l o w o r l d"
    //      | | | | | | | | | | 
    //      0 1 2 3 4 5 6 7 8 9
    
    //If m=1 and n=6, Result should be: "ellowo"
    
    char arr[100];
    int m,n = 0;
    
    printf("Enter string: ");
    scanf("%s", arr);
    printf("Enter m value: ");
    scanf("%d", &m);
    printf("Enter n value: ");
    scanf("%d", &n);

    //Error checking
    if(m > n){
        printf("Error: Invalid range\n");
        return 0;
    }

    //Ensure that the indices are within the bounds of the string
    if(m < 0 || n >= strlen(arr)){
        printf("Error: Indices are out of bounds!\n");
        return 0;
    }
        
    slice(arr, m, n);
    
    return 0;
}

void slice(char temp_arr[], int m, int n){
    for(int i=m; i<=n; i++){
        printf("%c", temp_arr[i]);
    }
    printf("\n");
    
}