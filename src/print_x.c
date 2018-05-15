/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:24:03 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/15 16:24:05 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_nbr(tf_list *lformat, uintmax_t nbr)
{
    char *str;
    int result;

    result = 0;
    if (lformat->conversion == 'x')
        str = itoa_base(nbr, 16, 'a');
    else
        str = itoa_base(nbr, 16, 'A');
    if (lformat->precision == 0 && nbr == 0 && lformat->width)
    {
        result += write(1, " ", 1);
        return (result);
    }
    else if (lformat->precision == 0 && nbr == 0 && lformat->width == 0 && !lformat->flags->hash)
        return (result);
    if (lformat->flags->minus)
        lformat->flags->zero = 0;
    if (lformat->flags->hash)
    {
        if (lformat->conversion == 'x')
            result += write(1, "0x", 2);
        else
            result += write(1, "0X", 2);
        lformat->flags->hash = 0;
    }
    if (!lformat->precision && !nbr)
        return (result);
    result += print_smth('0', lformat->precision - len_int(nbr));
    lformat->precision = 0;
    result += write(1, str, ft_strlen(str));
    free(str);
    return (result); 
}

int print_x(tf_list *lformat, uintmax_t nbr)
{
    int result;
    int sign;

    sign = 0;
    result = 0;
    if (lformat->flags->hash && nbr == 0)
        lformat->flags->hash = 0;
    if (lformat->flags->hash)
        sign = 2;
    if (lformat->flags->zero)
        if (lformat->flags->hash)
        {
            if (lformat->conversion == 'x')
                result += write(1, "0x", 2);
            else
                result += write(1, "0X", 2);
            lformat->flags->hash = 0;
        }
    if (lformat->flags->minus)
        result += print_nbr(lformat, nbr);
    if (len_int(nbr) > lformat->precision)
    {
        if(lformat->flags->zero)
            result += print_smth('0', lformat->width - len_int(nbr) - sign);
        else
        {   
            if (!lformat->flags->minus)
                result += print_smth(' ', lformat->width - len_int(nbr) - sign);
            else
                result += print_smth(' ', lformat->width - result);
        }
    }
    else
    {
        if(lformat->flags->zero)
            result += print_smth('0', lformat->width - lformat->precision - sign);
        else
            result += print_smth(' ', lformat->width - lformat->precision - sign);
        if (lformat->flags->hash)
        {
            if (lformat->conversion == 'x')
                result += write(1, "0x", 2);
            else
                result += write(1, "0X", 2);
            lformat->flags->hash = 0;
        }
        result += print_smth('0', lformat->precision - len_int(nbr) - sign);
        lformat->precision = 0;
    }
    if (!(lformat->flags->minus))
        result += print_nbr(lformat, nbr);
    return (result);
}