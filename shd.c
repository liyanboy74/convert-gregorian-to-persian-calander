// Edit By: Liyanboy74

#include <stdio.h>
#include "shd.h"

JalaliDate GregorianToJalali(int g_y, int g_m, int g_d)
{
    int g_days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int j_days_in_month[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};

    long int gy = g_y-1600;
    long int gm = g_m-1;
    long int gd = g_d-1;

    long int g_day_no,j_day_no;
    long int i,j_np,jy,j,jm,jd;

    JalaliDate Date;

    g_day_no = 365*gy;
    g_day_no+=(gy+3)/4;
    g_day_no-=(gy+99)/100;
    g_day_no+=(gy+399)/400;

    for (i=0; i < gm; ++i)
      g_day_no += g_days_in_month[i];
    if (gm>1 && ((gy%4==0 && gy%100!=0) || (gy%400==0)))
     // leap and after Feb
      g_day_no++;
    g_day_no += gd;

    j_day_no = g_day_no-79;

    j_np = j_day_no/ 12053;
    j_day_no = j_day_no % 12053;

    jy = 979+33*j_np+4*(j_day_no/1461);

    j_day_no %= 1461;

    if (j_day_no >= 366) {
      jy += (j_day_no-1)/365;
      j_day_no = (j_day_no-1)%365;
    }


    for (j=0; j < 11 && j_day_no >= j_days_in_month[j]; ++j)
      j_day_no -= j_days_in_month[j];
    jm = j+1;
    jd = j_day_no+1;

    Date.Day=jd;
    Date.Month=jm;
    Date.Year=jy;

    return Date;
}
