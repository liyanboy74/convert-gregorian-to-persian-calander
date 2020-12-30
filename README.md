# Convert Gregorian to Persian Calendar

Convert Gregorian date to Persian Calendar using C language.

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>
#include "shd.h"

int main(int argc, char *argv[]) {
	
	JalaliDate Date;
	
	Date=GregorianToJalali(2020,12,30);
	
	printf("%d,%d,%d\r\n",Date.Year,Date.Month,Date.Day);

	return 0;
}
```

