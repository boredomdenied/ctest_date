/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:51:21 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/07 03:28:25 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

t_elem	*find_or_create_node(t_elem **list, const int fd)
{
	while (*list && (*list)->fd != fd)
		list = &(*list)->next;
	if (!*list)
	{
		if (!(*list = (t_elem*)ft_memalloc(sizeof(t_elem))))
			return (NULL);
		if (!((*list)->chunk = ft_memalloc(BUFF_SIZE + 1)))
		{
			ft_memdel((void**)list);
			return (NULL);
		}
		(*list)->fd = fd;
	}
	return (*list);
}

int		ft_new_line(t_elem **list, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while ((*list)->chunk[len] != '\n' && (*list)->chunk[len] != '\0')
		len++;
	if ((*list)->chunk[len] == '\n')
	{
		*line = ft_strsub((*list)->chunk, 0, len);
		tmp = ft_strdup((*list)->chunk + len + 1);
		free((*list)->chunk);
		(*list)->chunk = tmp;
		if ((*list)->chunk[0] == '\0')
			ft_strdel(&(*list)->chunk);
	}
	else if ((*list)->chunk[len] == '\0')
	{
		*line = ft_strdup((*list)->chunk);
		ft_strdel(&(*list)->chunk);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_elem	*list;
	t_elem			*current;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	current = find_or_create_node(&list, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (current->chunk == NULL)
			current->chunk = ft_strnew(0);
		tmp = ft_strjoin(current->chunk, buf);
		free(current->chunk);
		current->chunk = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (current->chunk == NULL || current->chunk[0] == '\0'))
		return (0);
	return (ft_new_line(&current, line));
}
