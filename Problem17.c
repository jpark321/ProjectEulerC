#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int countOnes(const int n){
	int ones = n;
	if(ones == 1 || ones == 2 || ones == 6)
		return 3;
	else if(ones == 3 || ones == 7 || ones == 8)
		return 5;
	else if (ones == 4 || ones == 5 || ones == 9)
		return 4;
	else
		return 0;
}

int countTens(const int n){
	int count = 0;
	int tens = n;
	if((tens >= 10) && (tens < 20)){
		if(tens == 10)
			return 3;
		else if(tens == 11 || tens == 12)
			return 6;
		else if(tens == 13 || tens == 14 || tens == 18 || tens == 19)
			return 8;
		else if(tens == 15 || tens == 16)
			return 7;
		else if(tens == 17)
			return 9;
	}
	else{
		if((tens >= 20 && tens < 40) || (tens >= 80))
			count += 6;
		else if(tens >= 40 && tens < 70)
			count += 5;
		else if(tens >= 70 && tens < 80)
			count += 7;
		count += countOnes(tens%10);
		return count;
	}
	return 0;
}

int countHundreds(const int n){
	int count = 0;
	int tens = n%100;
	//printf("%d\n", n/100);
	if(!(tens)){
		//printf("no tens\n");
		//printf("countOnes(n/100): %d\n", countOnes(n/100));
		return countOnes(n/100) + 7;
	}
	return countOnes(n/100) + 7 + 3 + countTens(tens);
}

int countThousand(int n){
	return n+11;
}


int countLetters(int i){
	if(i >= 100){
		//printf("count100\n");
		return countHundreds(i);
	}
	else if(i >= 10){
		//printf("count10\n");
		return countTens(i);
	}
	else{
		//printf("count1\n");
		return countOnes(i);
	}
}


int main(){
	int count = 0;
	for(int i  = 1; i < 1000; i++){
		//printf("%d\n", i);
		count += countLetters(i);
	}
	count = countThousand(count);
	for(int i  = 1; i < 22; i++)
		printf("%d ", countLetters(i));
	printf("\n");
	printf("%d\n", count);

	return 0;
}
