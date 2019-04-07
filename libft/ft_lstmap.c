/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 00:43:08 by bchapman          #+#    #+#             */
/*   Updated: 2019/02/21 12:25:13 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
	{
		fresh = ft_lstmap(lst->next, f);
		ft_lstadd(&fresh, f(lst));
	}
	else
		fresh = f(lst);
	return (fresh);
}
