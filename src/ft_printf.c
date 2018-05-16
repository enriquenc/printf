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

#include "ft_printf.h"

static void lst_init(tf_list **lformat)
{
    (*lformat)->flags->minus = 0;
    (*lformat)->flags->zero = 0;
    (*lformat)->flags->plus = 0;
    (*lformat)->flags->space = 0;
    (*lformat)->flags->hash = 0;
    (*lformat)->width = 0;
    (*lformat)->precision = -1;
    (*lformat)->size = NULL;
    (*lformat)->conversion = -1;
}

int print(tf_list *lformat, va_list *list)
{
    int result;

    result = 0;
    if (lformat->conversion == '%')
        result += print_percent(lformat);
    if (lformat->conversion == 'd')
        result += print_d(lformat, list);
    else if (lformat->conversion == 'x' || lformat->conversion == 'X' || lformat->conversion == 'u' || lformat->conversion == 'o')
        result += start_x_o_u(lformat, list);
    else if (lformat->conversion == 'c')
        result += print_c(lformat, list);
    return (result);
}

int parse_start(va_list *list, const char *format)
{
    int result;
    tf_list *lformat;

    result = 0;
    lformat = (tf_list *)malloc(sizeof(tf_list));
    lformat->flags = (t_flags *)malloc(sizeof(tf_list));
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            lst_init(&lformat);
            parse_flags(&format, lformat);
            parse_width(&format, lformat, list);
            if (*format == '.')
                parse_precision(&format, lformat, list);
            parse_size(&format, lformat);
            parse_conversion(&format, lformat);
            result += print(lformat, list);
        }
        else
        {
            result += write(1, &(*format), 1);
            format++;
        }
    }
    free(lformat->flags);
    free(lformat);
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
