#include <math.h>
#include <stdio.h>

//A function to find largest prime factor
long long maxPrimeFactor(long long n){
	//Initialize the maximum prime factor
	//variable with the lowest one
	long long maxPrime = -1;

	//Print the number of 2s that devide n
	while(!(n&1)) {
		maxPrime = 2;
		n >>= 1; //equivalent to n /= 2
	}


	//n must be odd at this point, thus skip
	//the even numbers and iterate only for
	//odd integers
	for(int i =3; i <= sqrt(n); i+= 2) {
		while(n%i == 0){
			maxPrime = i;
			n = n/i;
		}
	}

	//This condition is to handle the case
	//when n is a prime number greater than 2
	if(n>2)
		maxPrime = n;
	return maxPrime;
}

//Driver program to test maxPrimeFactor function
int main(){
	long long n = 600851475143;
	printf("%lld\n", maxPrimeFactor(n));
	return 0;
}




