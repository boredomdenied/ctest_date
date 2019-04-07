/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:30:44 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/24 02:44:54 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t dstsize)
{
	size_t i;
	size_t len_dst;
	size_t len_src;

	i = 0;
	len_dst = ft_strlen(s1);
	len_src = ft_strlen(s2);
	if (dstsize == 0)
		return (0);
	if (dstsize - 1 <= len_dst)
		return (len_src + dstsize);
	while ((len_dst + i) < dstsize - 1)
	{
		s1[len_dst + i] = s2[i];
		i++;
	}
	s1[len_dst + i] = '\0';
	return (len_dst + len_src);
}
