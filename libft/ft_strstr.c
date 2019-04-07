/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:50:22 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/20 20:58:30 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (needle[0] == '\0')
		return (((char*)hay));
	while (hay[i] != '\0')
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
