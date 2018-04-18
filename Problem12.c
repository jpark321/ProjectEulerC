#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int triangulate(int n){
	return ((n+1)*n/2);
}

int numFactors(int n){
	int count = 1;
	for(int i = 1; i <= sqrt(n); i++){
		if(n%i == 0)
			count++;
	}
	return count*2;
}

int main(){

	int triangle = 1;
	for(int i = 1; numFactors(triangle) < 500; i++){
		triangle = triangulate(i);
	}
	printf("Triangle Number: %d\n", triangle);
	printf("Num of Factors: %d\n", numFactors(triangle));
	return 0;
}
