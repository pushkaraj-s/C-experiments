#include <stdio.h>

//Print Numbers from 1 to 10 except 6
//Make use of Break; continue; keywords

int main(){

	for(int i=0; i <=10; i++){
		
		if(i == 6){
			continue;
		}
		printf("%d \n", i);
	}


	return 0;
}
