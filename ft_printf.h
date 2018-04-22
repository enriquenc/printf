/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:21:05 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/16 15:21:07 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

typedef struct s_flags
{
    int minus;
    int zero;
    int plus;
    int space;
    int hash;
} t_flags;

typedef struct sf_list
{
    t_flags *flags;
    int width;
    int precision;
    char *size;
    char conversion;
} tf_list;

# endif