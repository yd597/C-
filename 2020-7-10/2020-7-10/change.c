#include <stdio.h>

#define  CHANGE(a)   ((a&0x55555555)<<1)
int main()
{
	int a = 5;
	printf("%d\n",CHANGE(a) );
	
	return 0;
}