/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:05:25 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/11 14:05:42 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void pass_spaces(const char **format)
{
    while(**format == ' ')
        (*format)++;
}
