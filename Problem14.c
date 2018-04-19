#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BELOW 1000000

int collatz(long n){
	int count = 0;
	while(n != 1){
		count++;
		if(!(n%2))
			n = n >> 1;
		else
			n = 3*n + 1;
	}
	count++;
	return count;
}

int main(){
	int count = 0;
	int max = 0;
	int num = 0;
	for(int i = BELOW/2; i < BELOW; i++){
		count = collatz(i);
		if(count > max){
			num = i;
			max = count;
			printf("num: %d, count: %d\n", num, count);
		}
		count = 0;
	}


	return 0;
}
