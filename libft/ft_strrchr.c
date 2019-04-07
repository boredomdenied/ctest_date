/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 06:48:17 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/19 21:55:18 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		while (((unsigned char*)s)[i])
			i++;
		return (&((char*)s)[i]);
	}
	while (((unsigned char*)s)[i])
		i++;
	i--;
	while (((unsigned char*)s)[i] != ((unsigned char)c)
			&& i > 0)
		i--;
	if (((unsigned char*)s)[i] == ((unsigned char)c))
		return (&((char*)s)[i]);
	return (NULL);
}
