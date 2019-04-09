/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 09:28:04 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/08 11:46:11 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (!(temp = (void*)malloc((size))))
		return (NULL);
	if (size > 0)
	{
		while (size > i)
		{
			temp[i++] = 0;
		}
	}
	return (temp);
}
