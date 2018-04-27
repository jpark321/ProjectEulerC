#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UPPER 10000


int main(){
	int x[UPPER];
	int sum = 0;
	for(int i = 0; i < UPPER; i++)
		x[i] = 0;

	for(int i = 0; i < UPPER; i++){
		int k = 2*i+1;
		while(k < UPPER){
			x[k] += i+1;
			k += i+1;
		}
	}

	for(int i = 0; i < UPPER; i++){
		for(int j = i+1; j < UPPER; j++){
			if(x[i] == j+1 && x[j] == i+1 && i != j){
				sum += x[i]+x[j];
				printf("i %d:%d\n", i+1, x[i]);
				printf("j %d:%d\n", j+1, x[j]);
			}
		}
	}

	printf("Sum: %d\n", sum);
	return 0;
}
