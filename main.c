#include "include/ft_printf.h"
#include <stdio.h>
#include <locale.h>



int main()
{   
    int nbr;
    setlocale(LC_CTYPE, "");
    /*D, d, i*/
    ft_printf("*******************************\n");
    ft_printf("d and i \nvalue = 42\n1 - yours \n2 - oroginal\n");
    ft_printf("*******************************\n");

    ft_printf("|@moulitest: %.d %.0d|\n", 0, 0);
    printf("|@moulitest: %.d %.0d|\n\n", 0, 0);

    ft_printf("|@moulitest: %5.d %5.0d|\n", 0, 0);
    printf("|@moulitest: %5.d %5.0d|\n\n", 0, 0);

    ft_printf("|%03.2d|\n", 0); 
    printf("|%03.2d|\n\n", 1); 

    ft_printf("|%+d|\n", 0);
    printf("|%+d|\n\n", 0);

    ft_printf("|%-5d|\n", 42);
    printf("|%-5d|\n\n", 42);
    
    ft_printf("|%-10.5d|\n", 4242);
    printf("|%-10.5d|\n\n", 4242);

    ft_printf("% d\n", 42);
    printf("% d\n\n", 42);

    ft_printf("%12d\n", 42);
    printf("%12d\n\n", 42);

    ft_printf("%012d\n", 42);
    printf("%012d\n\n", 42);

    ft_printf("% 012d\n", 42);
    printf("% 012d\n\n", 42);

    ft_printf("%+12d\n", 42);
    printf("%+12d\n\n", 42);

    ft_printf("%+012d\n", 42);
    printf("%+012d\n\n", 42);

    ft_printf("%-12d\n", 42);
    printf("%-12d\n\n", 42);

    ft_printf("%- 12d\n", 42);
    printf("%- 12d\n\n", 42);

    ft_printf("%-+12d\n", 42);
    printf("%-+12d\n\n", 42);
    
    ft_printf("%12.4d\n", 42);
    printf("%12.4d\n\n", 42);

    ft_printf("%-12.4d\n", 42);
    printf("%-12.4d\n\n", 42);

    ft_printf("*******************************\n");
    ft_printf("d and i \nvalue = -42\n1 - yours \n2 - oroginal\n");
    ft_printf("*******************************\n");
    ft_printf("%12d\n", -42);
    printf("%12d\n\n", -42);

    ft_printf("%012d\n", -42);
    printf("%012d\n\n", -42);

    ft_printf("% 012d\n", -42);
    printf("% 012d\n\n", -42);

    ft_printf("%+12d\n", -42);
    printf("%+12d\n\n", -42);

    ft_printf("%+012d\n", -42);
    printf("%+012d\n\n", -42);

    ft_printf("%-12d\n", -42);
    printf("%-12d\n\n", -42);

    ft_printf("%- 12d\n", -42);
    printf("%- 12d\n\n", -42);

    ft_printf("%-+12d\n", -42);
    printf("%-+12d\n\n", -42);
    
    ft_printf("%12.4d\n", -42);
    printf("%12.4d\n\n", -42);

    ft_printf("%-12.4d\n", -42);
    printf("%-12.4d\n\n", -42); 
    
    nbr = 42;
    ft_printf("*******************************\n");
    ft_printf("u \nvalue = %d\n1 - yours \n2 - oroginal\n", 42);
    ft_printf("*******************************\n");

    ft_printf("%o\n", 40);
    printf("%o\n\n", 40);
    
    ft_printf("%12u\n", nbr);
    printf("%12u\n\n", nbr);

    ft_printf("%12u\n", nbr);
    printf("%12u\n\n", nbr);

    ft_printf("%012u\n", nbr);
    printf("%012u\n\n", nbr);

    ft_printf("%12u\n", nbr);
    printf("%12u\n\n", nbr);

    ft_printf("%012u\n", nbr);
    printf("%012u\n\n", nbr);

    ft_printf("%-12u\n", nbr);
    printf("%-12u\n\n", nbr);

    ft_printf("%-12u\n", nbr);
    printf("%-12u\n\n", nbr);

    ft_printf("%-12u\n", nbr);
    printf("%-12u\n\n", nbr);
    
    ft_printf("%12.4u\n", nbr);
    printf("%12.4u\n\n", nbr);

    ft_printf("%-12.4u\n", nbr);
    printf("%-12.4u\n\n", nbr);

    nbr = -42;
    ft_printf("*******************************\n");
    ft_printf("u \nvalue = %d\n1 - yours \n2 - oroginal\n", nbr);
    ft_printf("*******************************\n");

    ft_printf("%12u\n", nbr);
    printf("%12u\n\n", nbr);

    ft_printf("%012u\n", nbr);
    printf("%012u\n\n", nbr);

    ft_printf("%012u\n", nbr);
    printf("%012u\n\n", nbr);

    ft_printf("%12u\n", nbr);
    printf("%12u\n\n", nbr);

    ft_printf("%012u\n", nbr);
    printf("%012u\n\n", nbr);

    ft_printf("%-12u\n", nbr);
    printf("%-12u\n\n", nbr);

    ft_printf("%-12u\n", nbr);
    printf("%-12u\n\n", nbr);

    ft_printf("%-12u\n", nbr);
    printf("%-12u\n\n", nbr);
    
    ft_printf("%12.4u\n", nbr);
    printf("%12.4u\n\n", nbr);

    ft_printf("%-12.4u\n", nbr);
    printf("%-12.4u\n\n", nbr); 

    
    ft_printf("@moulitest: %#.o %#.0o|\n", 0, 0);
    printf("@moulitest: %#.o %#.0o\n\n", 0, 0);

    ft_printf("%#6o\n", 2500);
    printf("%#6o\n\n", 2500);

    ft_printf("|%-05o|\n", 2500);
    ft_printf("|%-05o|\n\n", 2500);

    ft_printf("|%-5.10o|\n", 2500);
    printf("|%-5.10o|\n\n", 2500);

    ft_printf("|%-10.5o|\n", 2500);
    printf("|%-10.5o|\n\n", 2500);

    ft_printf("|@moulitest: %5.o %5.0o|\n", 0, 0);
    printf("|@moulitest: %5.o %5.0o|\n\n", 0, 0);

    unsigned char bytes[4];
    bytes[3] = 0;
    bytes[2] = 0;
    bytes[0] = 206;
    bytes[1] = 177;
    write(1, bytes, 2);
    ft_printf("%c\n", 's');
    printf("%c\n\n", 's');                    
    ft_printf("%C\n", L'α');
    printf("%C\n\n", L'α');
    ft_printf("%C\n", L'훘');
    printf("%C\n\n", L'훘');
    ft_printf("%C\n", L'𘚠');
    printf("%C\n\n", L'𘚠');
    return 0;
}
