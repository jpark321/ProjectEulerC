#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void multiply(int * num){
	int carry = 0;
	for(int i = 399; i >= 0; i--){
		num[i] *= 2;
		if(carry){
			carry = 0;
			num[i]++;
		}
		if(num[i] >= 10){
			carry = 1;
			num[i] %= 10;
		}
	}

}

int main(){
	int num[400];
	int leading = 1;
	int sum = 0;
	for(int i = 0; i < 400; i++){
		num[i] = 0;
	}
	num[399] = 2;

	for(int k = 1; k < 1000; k++)
		multiply(num);

	for(int i = 0; i < 400; i++){	
		if(!(leading))
			printf("%d", num[i]);
		if(num[i] && (leading)){
			leading = 0;
			printf("%d", num[i]);
		}
	}

	printf("\n");
	for(int i = 0; i < 400; i++){
		sum += num[i];
	}
	printf("\n");
	printf("%d\n", sum);
	return 0;
}
