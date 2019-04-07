/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 07:21:52 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/20 13:28:54 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (void*)s1;
	str2 = (void*)s2;
	i = 0;
	while (i < n && (str1[i] == str2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return (str1[i] - str2[i]);
}
