#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int main(){
	FILE *fp = fopen("Problem13LargeNum.txt", "r");
	int x[100][50];
	int y[50];
	char c;
	int carry = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 50; j++){
			x[i][j] = 0;
			y[j] = 0;
		}
	}
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 50; j++){
			fscanf(fp, "%c", &c);
			if(c == '\n')
				fscanf(fp, "%c", &c);
			x[i][j] = c - '0';
			if(i == 0)
				y[j] = x[i][j];
		}
	}

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 50; j++){
			printf("%d ", x[i][j]);
			if(j == 49)
				printf("\n");
		}
	}

	for(int i = 1; i < 100; i++){
		for(int j = 49; j >= 0; j --){
			if(carry){
				y[j] += 1;
				carry = 0;
			}
			y[j] += x[i][j];
			if(y[j] >= 10 && j != 0)
				carry = 1;
			if(j != 0)
				y[j] %= 10;
		}
		/*printf("\n");
		for(int k = 0; k < 50; k++)
			printf("%d ", y[k]);
		printf("\n");*/
	}

	printf("\n");

	for(int i = 0; i < 50; i++)
		printf("%d ", y[i]);

	printf("\n");
	fclose(fp);
	return 0;
}
