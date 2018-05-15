/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:47:55 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/07 16:48:01 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_nbr(tf_list *lformat, intmax_t nbr)
{
    char *str;
    int result;

    result = 0;
    str = ft_itoa(nbr);
    result += print_smth('0', lformat->precision - len_int(nbr));
    lformat->precision = 0;
    result += write(1, str, ft_strlen(str));
    free(str);
    return (result); 
}

int print_u(tf_list *lformat, uintmax_t nbr)
{
    int result;

    result = 0;
    if (lformat->flags->minus)
        result += print_nbr(lformat, nbr);
    if (len_int(nbr) > lformat->precision)
    {
        if(lformat->flags->zero)
            result += print_smth('0', lformat->width - len_int(nbr));
        else
            result += print_smth(' ', lformat->width - len_int(nbr));
    }
    else
    {
        if(lformat->flags->zero)
            result += print_smth('0', lformat->width - lformat->precision);
        else
            result += print_smth(' ', lformat->width - lformat->precision);
        result += print_smth('0', lformat->precision - len_int(nbr));
        lformat->precision = 0;
    }
    if (!(lformat->flags->minus))
        result += print_nbr(lformat, nbr);
    return (result);
}