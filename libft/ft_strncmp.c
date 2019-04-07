/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:06:29 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/24 04:02:51 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2 && n > 0)
		while (*s1 == *s2)
		{
			if (*s1 == '\0' || n == 1)
				return (0);
			s1++;
			s2++;
			n--;
		}
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
