# Convert Gregorian to Persian Calendar

Convert Gregorian date to Persian Calendar using C language.

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>
#include "shd.h"

int main(int argc, char *argv[]) {
	
	ShamsiDate Date;
	
	Date=GregorianToJalali(2020,5,6);
	
	printf("%d,%d,%d\r\n",Date.Year,Date.Month,Date.Day);

	return 0;
}
```

