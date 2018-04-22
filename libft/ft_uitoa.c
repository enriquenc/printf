/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 05:18:42 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/22 05:18:43 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned long long n)
{
	char	*res;
	int		size;
	unsigned long long int	i;

	size = 1;
	i = n;
	while ((i = i / 10))
		size++;
	if ((res = (char *)malloc(sizeof(*res) * size + 1)) == NULL)
		return (NULL);
	res[size--] = '\0';
	res[size--] = n % 10 + 48;
	while ((n = n / 10))
		res[size--] = n % 10 + 48;
	return (res);
}
