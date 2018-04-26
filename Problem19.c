#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int checkleap(int year){
	int leap = 0;
	if((year%4 == 0) && ((year%100 != 0) || (year%400 == 0)))
		leap = 1;
	return leap;
}

void increment(int* year, int* month, int* day_month, int* day_week){
	if(*day_week == 7)
		*day_week = 1;
	else
		*day_week += 1;
	if(*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10){
		if(*day_month < 31){
			*day_month += 1;
			//printf("%d:%d ", *day_month, *day_week);
		}
		else{
			*day_month = 1;
			*month += 1;
			//printf("\nMonth: %d\n", *month);
		}
	}
	else if(*month == 4 || *month == 6 || *month == 9 || *month == 11){
		if(*day_month < 30){
			*day_month += 1;
			//printf("%d:%d ", *day_month, *day_week);
		}
		else{
			*day_month = 1;
			*month += 1;
			//printf("\nMonth: %d\n", *month);
		}
	}
	else if(*month == 12){
		if(*day_month < 31){
			*day_month += 1;
			//printf("%d:%d ", *day_month, *day_week);
		}
		else{
			*day_month = 1;
			*month = 1;
			*year += 1;
			//printf("\nYear: %d\n", *year);
		}
	}
	else if(*month == 2){
		if(checkleap(*year)){
			if(*day_month < 29){
				*day_month += 1;
				//printf("%d:%d ", *day_month, *day_week);
			}
			else{
				*day_month = 1;
				*month += 1;
				//printf("\nMonth: %d\n", *month);
			}
		}
		else{
			if(*day_month < 28){
				*day_month += 1;
				//printf("%d:%d ", *day_month, *day_week);
			}
			else{
				*day_month = 1;
				*month += 1;
				//printf("\nMonth: %d\n", *month);
			}
		}
	}
	else
		printf("ERROR: INVALID DATE\n");
}	

int main(){
	int count = 0;
	int year = 1901;
	int month = 1;
	int day_month = 1;
	int day_week = 2;
	printf("Counting Sundays...\n");
	while(year < 2001){
		//printf("%d.%d.%d: %d ",year, month, day_month, day_week);
		if(day_week == 7 && day_month == 1){
			printf("\n");
			printf("%d.%d.%d: %d\n",year, month, day_month, day_week);
			count++;
		}
		increment(&year, &month, &day_month, &day_week);
	}

	printf("Count: %d\n", count);

	return 0;

}
