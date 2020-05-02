#include <stdio.h>
#include <stdlib.h>

typedef struct _ShamsiDate
{
int iYear;
int iMonth;
int iDay;
}ShamsiDate;

ShamsiDate MiladiToShamsi(int iMiladiDay,int iMiladiMonth,int iMiladiYear);

int main(int argc, char *argv[]) {
	
	ShamsiDate Date;
	
	Date=MiladiToShamsi(2,5,2092);
	
	printf("%d,%d,%d\r\n",Date.iYear,Date.iMonth,Date.iDay);

	return 0;
}

char MiladiIsLeap(int miladiYear)
{
	if(((miladiYear % 100)!= 0 && (miladiYear % 4) == 0) || ((miladiYear % 100)== 0 && (miladiYear % 400) == 0))
		return 1;
	else
		return 0;
}
 
ShamsiDate MiladiToShamsi(int iMiladiDay,int iMiladiMonth,int iMiladiYear)
{
	int  shamsiDay, shamsiMonth, shamsiYear;
	int  dayCount,farvardinDayDiff,deyDayDiff ;
	int  sumDayMiladiMonth[] = {0,31,59,90,120,151,181,212,243,273,304,334};
	int  sumDayMiladiMonthLeap[]= {0,31,60,91,121,152,182,213,244,274,305,335};
	ShamsiDate  ShamsiDate;
	 
	farvardinDayDiff=79;
	 
	if (MiladiIsLeap(iMiladiYear))
	{
		dayCount = sumDayMiladiMonthLeap[iMiladiMonth-1] + iMiladiDay;
	}
	else
	{
		dayCount = sumDayMiladiMonth[iMiladiMonth-1] + iMiladiDay;
	}
	if((MiladiIsLeap(iMiladiYear - 1)))
	{
		deyDayDiff = 11;
	}
	else
	{
		deyDayDiff = 10;
	}
	if (dayCount > farvardinDayDiff)
	{
		dayCount = dayCount - farvardinDayDiff;
		if (dayCount <= 186)
		{
			switch (dayCount%31)
			{
				case 0:
				shamsiMonth = dayCount / 31;
				shamsiDay = 31;
				break;
				default:
				shamsiMonth = (dayCount / 31) + 1;
				shamsiDay = (dayCount%31);
				break;
			}
			shamsiYear = iMiladiYear - 621;
		}
		else
		{
			dayCount = dayCount - 186;
			switch (dayCount%30)
			{
				case 0:
				shamsiMonth = (dayCount / 30) + 6;
				shamsiDay = 30;
				break;
				default:
				shamsiMonth = (dayCount / 30) + 7;
				shamsiDay = (dayCount%30);
				break;
			}
			shamsiYear = iMiladiYear - 621;
		}
	}
	else
	{
		dayCount = dayCount + deyDayDiff;
		 
		switch (dayCount%30)
		{
			case  0:
			shamsiMonth = (dayCount / 30) + 9;
			shamsiDay = 30;
			break;
			default:
			shamsiMonth = (dayCount / 30) + 10;
			shamsiDay = (dayCount%30);
			break;
		}
		shamsiYear = iMiladiYear - 622;		 
	}
	ShamsiDate.iYear = shamsiYear;
	ShamsiDate.iMonth = shamsiMonth;
	ShamsiDate.iDay = shamsiDay;
	 
	return ShamsiDate ;
}

