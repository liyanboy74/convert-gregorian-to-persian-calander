#include <stdio.h>
#include <stdlib.h>

typedef struct
{
int Year;
int Month;
int Day;
}ShamsiDate;

ShamsiDate GregorianToJalali(int g_y, int g_m, int g_d);

int main(int argc, char *argv[]) {
	
	ShamsiDate Date;
	
	Date=GregorianToJalali(2020,5,6);
	
	printf("%d,%d,%d\r\n",Date.Year,Date.Month,Date.Day);

	return 0;
}

ShamsiDate GregorianToJalali(int g_y, int g_m, int g_d)
{

int g_days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int j_days_in_month[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};

int gy = g_y-1600;
int gm = g_m-1;
int gd = g_d-1;

ShamsiDate Date;

long int g_day_no = 365*gy;
g_day_no+=(gy+3)/4;
g_day_no-=(gy+99)/100;
g_day_no+=(gy+399)/400;

for (int i=0; i < gm; ++i)
  g_day_no += g_days_in_month[i];
if (gm>1 && ((gy%4==0 && gy%100!=0) || (gy%400==0)))
 // leap and after Feb 
  g_day_no++;
g_day_no += gd;

int j_day_no = g_day_no-79;

int j_np = j_day_no/ 12053;
j_day_no = j_day_no % 12053;

int jy = 979+33*j_np+4*(j_day_no/1461);

j_day_no %= 1461;

if (j_day_no >= 366) {
  jy += (j_day_no-1)/365;
  j_day_no = (j_day_no-1)%365;
}

int j;
for (j=0; j < 11 && j_day_no >= j_days_in_month[j]; ++j)
  j_day_no -= j_days_in_month[j];
int jm = j+1;
int jd = j_day_no+1;

Date.Day=jd;
Date.Month=jm;
Date.Year=jy;

return Date;
}  
