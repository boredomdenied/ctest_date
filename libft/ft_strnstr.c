/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:46:59 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/20 20:58:06 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t l)
{
	int		i;
	int		j;
	size_t	n;

	i = 0;
	if (needle[i] == '\0')
		return (((char*)hay));
	n = ft_strlen(needle);
	while (hay[i] != '\0' && l-- >= n)
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (&((char*)hay)[i]);
		}
		i++;
	}
	return (NULL);
}
