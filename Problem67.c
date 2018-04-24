#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	FILE * fp = fopen("Problem67triangle.txt", "r");
	int n = 100;
	int x[(n+1)*n/2];
	char * line;
	char * token;
	size_t len = 0;
	for(int i = 0; i < n; i++){
		int nread = getline(&line, &len, fp);
		token = strtok(line, " ");
		for(int j = 0; j <= i; j++){
			x[(i+1)*i/2+j] = strtol(token, NULL, 10);
			token = strtok(NULL, " ");
		}
	}


	int row = 1;
	printf("Row 1: ");
	for(int i = 0; i < (n+1)*n/2; i++){
		printf("%d ", x[i]);
		if(i+1 == (row)*(row+1)/2){
			printf("\n");
			if((row)*(row+1)/2 != n*(n+1)/2)
				printf("Row %d: ", ++row);
		}
	}
	printf("\n");

	printf("Calculate Sum\n");
	for(int k = n-1; k > 0; k--){
		int i = k*(k-1)/2;
		for(int j = 0; j < k; j++){
			if(x[i+j+k] > x[i+j+k+1]){
				x[i+j] += x[i+j+k];
			}
			else{
				x[i+j] += x[i+j+k+1];
			}
		}
	}

	row = 1;
	printf("Row 1: ");
	for(int i = 0; i < (n+1)*n/2; i++){
		printf("%d ", x[i]);
		if(i+1 == (row)*(row+1)/2){
			printf("\n");
			if((row)*(row+1)/2 != n*(n+1)/2)
				printf("Row %d: ", ++row);
		}
	}
	printf("\n");

	free(line);
	free(token);
	return 0;
}
