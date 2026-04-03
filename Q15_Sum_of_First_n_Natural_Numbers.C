#include <stdio.h>

//Sum of n natural numbers

int main(){

	int n=0;
	int sum=0;
	printf("Enter a number: ");
	scanf("%d" , &n);


	for(int i=0; i <= n; i++){
		sum = sum + i;
	}
	printf("Sum of first %d numbers is: %d\n \n", n, sum);


	printf("Numbers in reverse order: \n");
	
	// Debug Print Statement
	// printf("%d", n);
	for(int j=n; j >= 0; j--){
		printf("%d \n", j);
	}

	return 0;
}
