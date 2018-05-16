/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:22:46 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/16 16:22:47 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t *get_str(tf_list *lformat, va_list *list)
{
    wchar_t *result;

    if (lformat->size)
        result = va_arg(*list, wchar_t *);
    else
        result = (wchar_t *)va_arg(*list, char *);
    return (result);
}

int write_str(char *str, tf_list *lformat)
{
    int result;

    result = 0;
    if (str == NULL)
    {
        str = "(null)";
        lformat->precision = 0;
    }
    else
    {
        if (lformat->precision > 0)
        {
            str[lformat->precision] = 0;
            if (!*str)
                lformat->precision = 0;
        }
        else
            lformat->precision = ft_strlen(str);
    }
    if (lformat->flags->minus)
        result += write(1, str, ft_strlen(str));
    result += print_smth(' ', lformat->width - lformat->precision);
    if (!lformat->flags->minus)
        result += write(1, str, ft_strlen(str)); 
    return (result);
}

int print_s(tf_list *lformat, va_list *list)
{
    int result;
    wchar_t *str;

    result = 0;
    str = get_str(lformat, list);
    if (!lformat->size)
    {
        result += write_str((char *)str, lformat);
        return (result);
    }
    else
    {
        while(*str)
        {
            result += check_mask(*str);
            str++;
        }
    }
    return (result);
}