/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:06:07 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/03 17:28:47 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static t_list	*search_in_list(t_list **list, int fd)
{
	t_list			*copy;
	t_list			*new;

	copy = *list;
	while (copy)
	{
		if (copy->content_size == (size_t)fd)
			return (copy);
		copy = copy->next;
	}
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = "";
	new->content_size = fd;
	new->next = NULL;
	ft_lstadd(list, new);
	return (*list);
}

static int		ft_reading(t_list **list, int fd)
{
	t_list			*lst;
	char			*reading;
	char			*search;
	long int		read_bytes;
	char			*stock;

	lst = *list;
	stock = ft_strdup(lst->content);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		reading = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		if ((read_bytes = read(fd, reading, BUFF_SIZE)))
		{
			reading[read_bytes] = '\0';
			search = ft_strjoin(stock, reading);
			free(reading);
			free(stock);
			stock = search;
			lst->content = stock;
		}
		if ((search = ft_strchr(lst->content, '\n')))
			break ;
	}
	return (read_bytes);
}

static int		cleaning(t_list **lst)
{
	t_list			*clone;
	char			*str;
	char			*forclean;

	clone = *lst;
	forclean = clone->content;
	str = ft_strnew(1);
	ft_memdel((void **)&forclean);
	clone->content = str;
	return (-1);
}

static int		checking(char *search, t_list **list,
	int read_bytes, char ***lne)
{
	t_list			*lst;
	char			**line;

	line = *lne;
	lst = *list;
	if (read_bytes == 0 && !ft_strchr(lst->content, '\n'))
	{
		if ((search = ft_strchr(lst->content, '\0')) == lst->content)
			return (0);
		if (!(*line = ft_strdup(lst->content)))
			return (-1);
		free(lst->content);
		lst->content = search;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*all_info;
	t_list			*lst;
	char			*search;
	long int		read_bytes;

	if (!line || fd < 0 || fd > 4864)
		return (-1);
	lst = search_in_list(&all_info, fd);
	read_bytes = ft_reading(&lst, fd);
	search = ft_strchr(lst->content, '\n');
	if (read_bytes < 0)
		return (cleaning(&lst));
	else if (search != NULL)
	{
		*search++ = '\0';
		search = ft_strdup(search);
		if (!(*line = ft_strdup(lst->content)))
			return (-1);
		free(lst->content);
		lst->content = search;
		return (1);
	}
	return (checking(search, &lst, read_bytes, &line));
}
