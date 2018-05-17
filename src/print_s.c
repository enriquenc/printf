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

wchar_t		*get_str(t_flist *lformat, va_list *list)
{
	wchar_t *result;

	if (lformat->size)
		result = va_arg(*list, wchar_t *);
	else
		result = (wchar_t *)va_arg(*list, char *);
	return (result);
}

void		write_str(char *s, t_flist *lformat, int *result)
{
	char	*str;
	int		print;

	print = 1;
	str = NULL;
	if (lformat->precision == 0)
		print = 0;
	if (s == NULL)
		str = ft_strdup("(null)");
	else if (lformat->precision)
	{
		str = ft_strdup(s);
		if (lformat->precision > 0 && lformat->precision < (int)ft_strlen(str))
			str[lformat->precision] = 0;
		else
			lformat->precision = ft_strlen(str);
	}
	if (lformat->flags->minus && print)
		(*result) += write(1, str, ft_strlen(str));
	if (lformat->precision == -1)
		lformat->precision = 0;
	(*result) += print_smth(' ', lformat->width - lformat->precision);
	if (!lformat->flags->minus && print)
		(*result) += write(1, str, ft_strlen(str));
	free(str);
}

int			check_size(wchar_t *str)
{
	int result;

	result = 0;
	while (*str)
	{
		if (*str < 128)
			result++;
		else if (*str < 2048)
			result += 2;
		else if (*str < 65536)
			result += 3;
		else
			result += 4;
		str++;
	}
	return (result);
}

int			print_s(t_flist *lformat, va_list *list)
{
	int		result;
	wchar_t	*str;

	result = 0;
	str = get_str(lformat, list);
	if (!lformat->size || str == NULL)
	{
		write_str((char *)str, lformat, &result);
		return (result);
	}
	else
	{
		while (lformat->flags->minus && *str)
		{
			result += check_mask(*str);
			str++;
		}
		result += print_smth(' ', lformat->width - check_size(str));
		while (!lformat->flags->minus && *str)
		{
			result += check_mask(*str);
			str++;
		}
	}
	return (result);
}
