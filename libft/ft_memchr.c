/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:45:33 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/24 04:04:33 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	size_t		len;
	char		*str;

	str = (void*)s;
	i = 0;
	len = ft_strlen(str);
	if (len < n)
		n = len;
	while (i < n && str[i] != ((char)c))
		i++;
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
