/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:56:30 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/16 13:08:06 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		number;
	int		negative;

	number = 0;
	while (*str == '\r' || *str == '\f' || *str == '\n' || *str == '\v' ||
			*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	if (negative < 0)
		return (number *= negative);
	return (number);
}
