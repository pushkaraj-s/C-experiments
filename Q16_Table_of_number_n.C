#include <stdio.h>

int main(){
	//Write a program which prints table of number input by user.
	int n;
	printf("Enter a Number: ");
	scanf("%d", &n);

	printf("Table of %d: \n" , n);
	for(int i=1; i <= 10; i++){
		printf("%d \n", n*i);
	}

	return 0;
}
