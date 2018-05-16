/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:21:58 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/15 19:29:44 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t get_char(tf_list *lformat, va_list *list)
{
    wchar_t result;

    if (lformat->size)
        result = va_arg(*list, wchar_t);
    else
        result = (char)va_arg(*list, int);
    return (result);
}

int check_mask(wchar_t chr)
{
    int result;
    unsigned char mask[4];

    result = 0;
    ft_bzero(mask, 4);
    if (chr < 128)
        result += write(1, &chr, 1);
    else if (chr < 2048)
    {
        mask[0] = 192 | ((chr >> 6) & 31);
        mask[1] = 128 | (chr & 63);
        result += write(1, mask, 2);
    }
    else if (chr < 65536)
    {
        mask[0] = 224 | ((chr >> 12) & 15);
        mask[1] = 128 | ((chr >> 6) & 63);
        mask[2] = 128 | (chr & 63);
        result += write(1, mask, 3);
    }
    else
    {
        mask[0] = 240 | ((chr >> 18) & 7);
        mask[1] = 128 | ((chr >> 12) & 63);
        mask[2] = 128 | ((chr >> 6) & 63);
        mask[3] = 128 | (chr & 63);
        result += write(1, mask, 4);
    }
    return (result);
}

int print_c(tf_list *lformat, va_list *list)
{
    int result;
    wchar_t chr;
    int bytes;

    result = 0;
    chr = get_char(lformat, list);
    if (chr < 128)
        bytes = 1;
    else if (chr < 2048)
        bytes = 2;
    else if (chr < 65536)
        bytes = 3;
    else
        bytes = 4;
    if (lformat->flags->minus)
        result += check_mask(chr);
    result += print_smth(' ', lformat->width - bytes);
    if (!lformat->flags->minus)
        result += check_mask(chr);
    return(result);
}