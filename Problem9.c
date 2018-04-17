#include <stdio.h>
#include <math.h>

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	const int sum = 1000;

	for(a = 1; a <= sum/3; a++){
		for(b = a+1; b <= sum/2; b++){
			c = sum - a - b;
			if(c*c == a*a + b*b){
				printf("Special Pythagorean Triplet: a=%d, b= %d, c=%d\n", a, b, c);
				printf("Final Product abc: %ld\n", (long)a*b*c);
		
			}

		}
	}
	
	return 0;
}
