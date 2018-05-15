/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:27:52 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/19 23:45:46 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*itoa_base(unsigned nbr, int base, char size)
{
	unsigned	temp;
	int		i;
	char	*res;

	temp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	i = 1;
	if (base < 2 || base > 16)
		return (NULL);
	while ((temp /= base))
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i--] = '\0';
	while (nbr)
	{
		if((nbr % base + 48) <= 57)
			res[i--] = nbr % base + 48;
		else
		{
			if (size == 'a')
				res[i--] = nbr % base + 87;
			else if (size == 'A')
				res[i--] = nbr % base + 55;
		}
		nbr = nbr / base;
	}
	return (res);
}
