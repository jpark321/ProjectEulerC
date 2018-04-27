#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void multiply(int * x, int n){
	int a = 0;
	int carry = 0;
	for(int i = 0; i < 200; i++){
		if(x[i]){
			a = i;
			break;
		}
	}
	for(int i = 199; i >= a - 2; i--){
		if(i == -1)
			break;
		x[i] *= n;
		x[i] += carry;
		carry = 0;
		if(i != 0){
			carry = x[i]/10;
			x[i] %= 10;
		}
	}


}


int main(){
	int x[200];
	int sum = 0;
	for(int i = 0; i < 200; i++){
		x[i] = 0;
	}
	x[199] = 1;

	for(int i = 2; i < 101; i++){
		multiply(x, i);
	}

	printf("num: ");
	int lead = 0;
	for(int i = 0; i < 200; i++){
		if(x[i] || lead){
			lead = 1;
			printf("%d ", x[i]);
		}
		sum += x[i];
	}
	printf("\n");
	
	printf("Sum: %d\n", sum);

	return 0;
}
