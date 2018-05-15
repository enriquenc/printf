/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:57:35 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/24 20:57:36 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int check_sign(tf_list *lformat, ssize_t nbr, t_sign *sign)
{
    int result;

    result = 0;
    sign->is_printed = 0;
    if (nbr < 0)
        result++;
    else if (lformat->flags->space && !(lformat->flags->plus) && nbr > 0)
    {
        result += write(1, " ", 1);
        sign->is_printed = 1;
    }
    else if (lformat->flags->plus)
        result++;
    sign->is_sign = result;
    if (sign->is_printed)
        return (1);
    else
        return (0);
}

int print_sign(tf_list *lformat, ssize_t *nbr, t_sign *sign)
{
    int result;

    result = 0;
    if (*nbr < 0)
    {
        result += write(1, "-", 1);
        *nbr *= -1;
        sign->is_printed = 1;
    }
    else if (lformat->flags->plus && *nbr >= 0 && !sign->is_printed)
    {
        result += write(1, "+", 1);
        sign->is_printed = 1;
    }
    return (result);
}

intmax_t get_nbr(tf_list *lformat, va_list *list)
{
    intmax_t nbr;

    nbr = 0;
    if (lformat->size)
    {
        if (lformat->size[0] == 'h' && lformat->size[1] == 'h')
            nbr = (signed char)va_arg(*list, int);
        else if (lformat->size[0] == 'h' && lformat->size[1] == '\0')
            nbr = (short)va_arg(*list, int);
        else if (lformat->size[0] == 'l' && lformat->size[1] == '\0')
            nbr = va_arg(*list, long int);
        else if (lformat->size[0] == 'l' && lformat->size[1] == 'l')
            nbr = va_arg(*list, long long int);
        else if (lformat->size[0] == 'j' && lformat->size[1] == '\0')
            nbr = va_arg(*list, intmax_t);
        else if (lformat->size[0] == 'z' && lformat->size[1] == '\0')
            nbr = va_arg(*list, ssize_t);
    }
    else
        nbr = va_arg(*list, int);
    return (nbr);
}

static int print_nbr(tf_list *lformat, intmax_t *nbr, t_sign *sign)
{
    char *str;
    int result;

    result = 0;
    if (lformat->precision == 0 && *nbr == 0 && lformat->width )
    {
        result += write(1, " ", 1);
        return (result);
    }
    else if (lformat->precision == 0 && *nbr == 0 && lformat->width == 0)
        return (result);
    result += print_sign(lformat, nbr, sign);
    str = ft_itoa(*nbr);
    lformat->flags->zero = 0;
    result += print_smth('0', lformat->precision - len_int(*nbr));
    if ((lformat->precision - len_int(*nbr)) > 0)
        lformat->width = lformat->width - (lformat->precision - len_int(*nbr));
    lformat->precision = 0;
    result += write(1, str, ft_strlen(str));
    free(str);
    return (result); 
}

int print_d(tf_list *lformat, va_list *list)
{
    intmax_t nbr;
    int result;
    int i;
    t_sign *sign = (t_sign *)malloc(sizeof(t_sign));

    nbr = get_nbr(lformat, list);
    result = 0;
    result += check_sign(lformat, nbr, sign);
    i = 0;
    if (lformat->flags->zero)
        result += print_sign(lformat, &nbr, sign);
    if (lformat->flags->minus)
        result += print_nbr(lformat, &nbr, sign);
    if (len_int(nbr) > lformat->precision)
    {
        if(lformat->flags->zero)
            result += print_smth('0', lformat->width - len_int(nbr) - sign->is_sign);
        else
            result += print_smth(' ', lformat->width - len_int(nbr) - sign->is_sign);
    }
    else
    {
        if(lformat->flags->zero)
            result += print_smth('0', lformat->width - lformat->precision - sign->is_sign);
        else
            result += print_smth(' ', lformat->width - lformat->precision - sign->is_sign);
        result += print_sign(lformat, &nbr, sign);
        result += print_smth('0', lformat->precision - len_int(nbr));
        lformat->precision = -1;
    }
    if (!(lformat->flags->minus))
        result += print_nbr(lformat, &nbr, sign);
    return (result);
}
