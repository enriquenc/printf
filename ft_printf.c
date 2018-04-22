/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:20:49 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/16 15:20:50 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void lst_init(tf_list **lformat)
{
    if (!*lformat)
    {
        (*lformat) = (tf_list *)malloc(sizeof(tf_list));
        (*lformat)->flags = (t_flags *)malloc(sizeof(tf_list));
    }
    (*lformat)->flags->minus = 0;
    (*lformat)->flags->zero = 0;
    (*lformat)->flags->plus = 0;
    (*lformat)->flags->space = 0;
    (*lformat)->flags->hash = 0;
    (*lformat)->width = -1;
    (*lformat)->precision = -1;
    (*lformat)->size = NULL;
    (*lformat)->conversion = -1;
}

void pass_spaces(const char **format)
{
    while(**format == ' ')
        (*format)++;
}

void parse_flags(const char **format, tf_list *lformat)
{
    while( **format == '-' || **format == '+' || **format == ' ' ||
        **format == '0' || **format == '#')
    {
        if (**format == ' ')
            lformat->flags->space = 1;
        else if (**format == '+')
            lformat->flags->plus = 1;
        else if (**format == '-')
            lformat->flags->minus = 1;
        else if (**format == '0')
            lformat->flags->zero = 1;
        else if (**format == '#')
            lformat->flags->hash = 1;
        (*format)++;
        if (**format == ' ')
            lformat->flags->space = 1;
        pass_spaces(format);
    }
}

void parse_width(const char **format, tf_list *lformat, va_list *list)
{
    if (**format == '*')
    {
        lformat->width = va_arg(*list, int);
        (*format)++;
        return;
    }
    if (ft_isdigit(**format))
    {
        lformat->width = atoi(*format);
        (*format) += len_int(lformat->width);
    } 
}

void parse_precision(const char **format, tf_list *lformat, va_list *list)
{
    if (**format == '.')
    {
        lformat->precision = 0;
        (*format)++;
    }
    if (**format == '*')
    {
        lformat->precision = va_arg(*list, int);
        (*format)++;
        return;
    }
    if (ft_isdigit(**format))
    {
        lformat->precision = atoi(*format);
        (*format) += len_int(lformat->width);
    }
}

void parse_size(const char **format, tf_list *lformat)
{
    if (**format == 'h' && *((*format) + 1) == 'h')
    {
        lformat->size = "hh";
        (*format) += 2;
    }
    else if (**format == 'l' && *((*format) + 1) == 'l')
    {
        lformat->size = "ll";
        (*format) += 2;
    }
    else if (**format == 'h')
    {
        lformat->size = "h";
        (*format)++;
    }
    else if (**format == 'l')
    {
        lformat->size = "l";
        (*format)++;
    }
    else if (**format == 'j')
    {
        lformat->size = "j";
        (*format)++;
    }
    else if (**format == 'z')
    {
        lformat->size = "z";
        (*format)++;
    }
}

void parse_conversion(const char **format, tf_list *lformat)
{
    if (**format == 'i' || **format == 'd' || **format == 'D')
        lformat->conversion = 'd';
    if (**format == 's' || **format == 'S')
        lformat->conversion = 's';
    if (**format == 'o' || **format == 'O')
        lformat->conversion = 'o';
    if (**format == 'u' || **format == 'U')
        lformat->conversion = 'u';
    if (**format == 'x')
        lformat->conversion = 'x';
    if (**format == 'X')
        lformat->conversion = 'X';
    if (**format == 'p')
        lformat->conversion = 'p';
    if (**format == 'c' || **format == 'C')
        lformat->conversion = 'c';
    if (**format == 'O' || **format == 'S' || **format == 'D' || **format == 'U' || **format == 'C')
        lformat->size = "l";
    (*format)++;
}

int print_d(tf_list *lformat, va_list *list)
{
    intmax_t nbr;
    int result;
    int i;
    char *str;

    nbr = va_arg(*list, intmax_t);
    if (lformat->size)
    {
        if (lformat->size[0] == 'h' && lformat->size[1] == 'h')
            nbr = (signed char)nbr;
        else if (lformat->size[0] == 'h' && lformat->size[1] == '\0')
            nbr = (short)nbr;
        else if (lformat->size[0] == 'l' && lformat->size[1] == '\0')
            nbr = (long)nbr;
        else if (lformat->size[0] == 'l' && lformat->size[1] == 'l')
            nbr = (long long)nbr;
        else if (lformat->size[0] == 'j' && lformat->size[1] == '\0')
            nbr = (intmax_t)nbr;
        else if (lformat->size[0] == 'z' && lformat->size[1] == '\0')
            nbr = (ssize_t)nbr;
    }
    else
        nbr = (int)nbr;
    result = 0;
    if (lformat->flags->space && !(lformat->flags->plus))
        result += write(1, " ", 1);
    if(lformat->flags->plus && nbr > 0)
        result += write(1, "+", 1);
    i = 0;
    while(i < lformat->width - lformat->precision && i < lformat->width - len_int(nbr))
    {
        if(lformat->flags->zero)
            result += write(1, "0" , 1);
        else
            result += write(1, " ", 1);
        i++;
    }
    while(i < lformat->width - len_int(nbr) - lformat->flags->space)
    {
        result += write(1, "0", 1);
        i++;
    }
    str = ft_itoa(nbr);
    result += write(1, str, ft_strlen(str));
    return result;
}

int print(tf_list *lformat, va_list *list)
{
    int result;

    result = 0;
    if (lformat->conversion == 'd')
       result += print_d(lformat, list);
    return result;
}

int parse_start(va_list *list, const char *format)
{
    int result;
    tf_list *lformat;

    result = 0;
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            if (*format == '%')
            {
                result += write(1, &(*format), 1);
                format++;
                continue ;
            }
            lst_init(&lformat);
            parse_flags(&format, lformat);
            parse_width(&format, lformat, list);
            if (*format == '.')
                parse_precision(&format, lformat, list);
            parse_size(&format, lformat);
            parse_conversion(&format, lformat);
            result += print(lformat, list);
        }
        result += write(1, &(*format), 1);
        format++;
    }
    return result;
}

int ft_printf(const char *format, ...)
{
    int result;
    va_list list;

    result = 0;
    if (format)
    {
        va_start(list, format);
        result = parse_start(&list, format);
    }
    return(result);
}

int main()
{
    ft_printf("% 012d\n", 45);
    printf("% 012d\n", 45);
    //printf("%d\n\n", ft_printf("%-o\n", 123));
    //printf("%d\n", printf("%-o\n", 123));    
    return 0;
}