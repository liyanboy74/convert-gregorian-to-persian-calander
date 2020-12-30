#ifndef _SHD_H_
#define _SHD_H_

typedef struct
{
int Year;
int Month;
int Day;
}JalaliDate;

JalaliDate GregorianToJalali(int g_y, int g_m, int g_d);

#endif // _SHD_H_
