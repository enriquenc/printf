/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:13:31 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/16 22:13:32 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_p(tf_list *lformat, va_list *list)
{
    int result;
    size_t p;
    char *str;

    result = 0;
    p = va_arg(*list, size_t);
    str = itoa_base(p, 16, 'a');
    if (lformat->flags->minus)
    {
        result += write(1, "0x", 2);
        result += write(1, str, ft_strlen(str));
    }
    result += print_smth(' ', lformat->width - ft_strlen(str) - 2);
    if (!lformat->flags->minus)
    {
        result += write(1, "0x", 2);
        result += write(1, str, ft_strlen(str));
    }
    return (result);
}
