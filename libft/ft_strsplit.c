/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:02:05 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/24 17:20:31 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		start;
	int		flag;

	i = -1;
	start = 0;
	j = 0;
	flag = 0;
	if (!s)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (ft_wc(s, c)) + 1)))
		return (NULL);
	while (s[++i])
	{
		if (s[i] == c && flag)
			arr[j++] = ft_strsub(s, start, i - start);
		if (!flag && s[i] != c)
			start = i;
		flag = (s[i] == c) ? 0 : 1;
	}
	if (flag)
		arr[j] = ft_strsub(s, start, i - start);
	return (arr);
}
