#include <stdio.h>

int main(){

	//Print 1(true) or 0(false) for following statements:

	// a. if it's sunday and it's snowing -> true
	// b. if it's monday and it's raining -> true
	// c. if number is greater than 9 and less than 100 -> true

	//a
	int isSunday = 1;
	int isSnowing = 1;

   	printf("%d \n", isSnowing && isSunday);

	//b
	int isMonday = 1;
	int isRaining = 1;

   	printf("%d \n", isMonday && isRaining);

	 //c
	int Number = 0;
	printf("Enter a Number = ");
	scanf("%d", &Number);

   	printf("%d \n", Number > 9 && Number < 100);
}
