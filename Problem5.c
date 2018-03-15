#include <stdio.h>

long gcd(long a, int b){
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

long lcm(long a, int b){
	return (a*b)/gcd(a, b);
}

long recurlcm(int n){
	long ret = 1;
	for(int i = 1; i <= n; i++){
		ret = lcm(ret, i);
	}
	return ret;
}

int main(){
	printf("%ld\n", recurlcm(20));
	return 0;
}
