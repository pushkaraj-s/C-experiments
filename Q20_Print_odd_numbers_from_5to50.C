#include <stdio.h>

//Print all odd numbers from 5 to 50

int main(){

	for(int i=5; i <=50; i++){
		if(i%2 == 1){
			printf("%d \n", i); //Doing mod to get reminder
		}
	}


}
