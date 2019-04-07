/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:27:34 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/24 17:01:37 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		length(int nbr)
{
	int size;

	if (nbr == 0)
		return (1);
	size = 0;
	if (nbr == -2147483648)
	{
		nbr /= 10;
		size++;
	}
	if (nbr < 0)
	{
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char	*post_malloc(int neg, int n, char *arr, int size)
{
	if (neg)
		arr[0] = '-';
	if (n == 0)
		arr[size + neg - 1] = '0';
	arr[size + neg] = '\0';
	while (n > 0)
	{
		arr[size + neg - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		max;
	int		size;
	char	*arr;

	size = 0;
	size = length(n);
	neg = 0;
	max = 0;
	if (n == -2147483648)
	{
		max = 1;
		n = -147483648;
	}
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	if (!(arr = (char*)malloc(sizeof(char) * (size + neg + max + 1))))
		return (NULL);
	if (max)
		arr[1] = '2';
	arr = post_malloc(neg, n, arr, size);
	return (arr);
}
