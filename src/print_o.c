/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:21:30 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/07 17:21:31 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int print_nbr(tf_list *lformat, uintmax_t nbr)
{
    char *str;
    int result;

    result = 0;
    str = itoa_base(nbr, 8, 'a');
    if (lformat->precision == 0 && nbr == 0 && lformat->width)
    {
        result += write(1, " ", 1);
        return (result);
    }
    else if (lformat->precision == 0 && nbr == 0 && lformat->width == 0 && !lformat->flags)
        return (result);
    if (lformat->flags->minus)
        lformat->flags->zero = 0;
    if (lformat->flags->hash)
    {
        result += write(1, "0", 1);
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

int print_o(tf_list *lformat, uintmax_t nbr)
{
    int result;
    int sign;

    sign = 0;
    result = 0;
    if (lformat->flags->hash)
        sign = 1;
    if (lformat->flags->zero)
        if (lformat->flags->hash)
        {
            result += write(1, "0", 1);
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
            result += write(1, "0", 1);
            lformat->flags->hash = 0;
        }
        result += print_smth('0', lformat->precision - len_int(nbr) - sign);
        lformat->precision = 0;
    }
    if (!(lformat->flags->minus))
        result += print_nbr(lformat, nbr);
    return (result);
}