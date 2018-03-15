#include <stdio.h>


int main(){
	int i = 1;
	int sum = 0;
	while(i < 1000){
		if((i%3 == 0) || (i%5 == 0)){
			sum += i;
		}
		i++;
	}
	printf("%d\n",sum);
	return 0;
}
