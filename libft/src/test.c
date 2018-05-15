#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int len_int(intmax_t n)
{
    int len;

    len = 1;
    while(n /= 10)
        len++;
    return (len);
}

int print_smth(char to_print, int length)
{
    int result;

    result = 0;
    while (length--)
        result += write(1, &to_print, 1);
    return (result);
}

int main(void)
{
	printf("\n%d", print_smth('0', 10));
	return 0;
}
