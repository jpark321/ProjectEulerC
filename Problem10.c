#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BELOW 2000000

int isPrime(int num){
	int i;
	for(i = 2; i <= sqrt(num); i++){
		if(num % i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int i;
	long sum = 0;
	for(i = 2; i < BELOW; i++){
		if(isPrime(i)){
			sum += i;
		}

	}
	printf("Sum of Primes: %ld\n", sum);

	return 0;
}
