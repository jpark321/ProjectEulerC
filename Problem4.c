#include <math.h>
#include <stdio.h>

int largestPalindrom(int n){
	int uplim = 0;
	
	for(int i = 1; i <= n; i++){
		uplim *= 10;
		uplim += 9;
	}
	int lowlim = 1+uplim/10;
	int max = 0;
	for(int i = uplim; i >= lowlim; i--){
		for(int j = i; j >= lowlim; j--){
			int product = i * j;
			if(product < max)
				break;
			int num = product;
			int reverse = 0;
			while(num !=0){
				reverse = reverse*10+num%10;
				num /= 10;
			}
			if(product == reverse && product > max)
				max = product;
		}
	}
	return max;
}

int main(){
	int n = 3;
	printf("%d\n", largestPalindrom(n));
	return 0;
}


