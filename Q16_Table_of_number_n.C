#include <stdio.h>

int main(){

	int n;
	printf("Enter a Number: ");
	scanf("%d", &n);

	printf("Table of %d: \n" , n);
	for(int i=1; i <= 10; i++){
		printf("%d \n", n*i);
	}

	return 0;
}
