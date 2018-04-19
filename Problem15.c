#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int a = 21, b = 21;
	long x[a][b];
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			if(i == 0 || j == 0)
				x[i][j] = 1;
			else
				x[i][j] = 0;
		}
	}
	for(int i = 1; i < a; i++){
		for(int j = 1; j < b; j++){
			x[i][j] = x[i-1][j]+ x[i][j-1];
		}
	}

	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			printf("%ld ", x[i][j]);
		}
		printf("\n");
	}


	return 0;
}
