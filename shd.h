#ifndef __SHD_H__
#define __SHD_H__

#ifdef __cplusplus
 extern "C" {
#endif
   
typedef struct
{
int Year;
int Month;
int Day;
}JalaliDate;

JalaliDate GregorianToJalali(int g_y, int g_m, int g_d);

#ifdef __cplusplus
}
#endif

#endif // __SHD_H__
