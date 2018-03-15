#include <stdio.h>

//sum of the squares of the first n natural numbers
long ssq(int n){
	long ret = 0;
	for(int i = 1; i <= n; i++)
		ret += i*i;
	return ret;
}

//square of the sum of the first n natural numbers
long sqs(int n){
	long ret = 0;
	for(int i = 1; i <= n; i++)
		ret += i;
	return ret*ret;
}

int main(){
	printf("%ld", sqs(100)-ssq(100));
	return 0;
}
