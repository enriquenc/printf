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
#include "../libft/include/libft.h"

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

typedef struct s_sign
{
    int is_sign;
    int sign;
    int is_printed;
} t_sign;

int ft_printf(const char *format, ...);
int print_d(tf_list *lformat, va_list *list);
int start_x_o_u(tf_list *lformat, va_list *list);
int print_smth(char to_print, int length);
void pass_spaces(const char **format);
void parse_width(const char **format, tf_list *lformat, va_list *list);
void parse_precision(const char **format, tf_list *lformat, va_list *list);
void parse_size(const char **format, tf_list *lformat);
void parse_conversion(const char **format, tf_list *lformat);
void parse_flags(const char **format, tf_list *lformat);
int print_o(tf_list *lformat, uintmax_t nbr);
int print_u(tf_list *lformat, uintmax_t nbr);

# endif