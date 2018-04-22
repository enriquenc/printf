#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int main(void)
{
	int *p;
	int a;
	a = 5;
	*p = a;
	
	printf("%p", p);
	return 0;
}
