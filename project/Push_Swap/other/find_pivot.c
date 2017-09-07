/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					*ft_sort_array(int *array, int len)
{
	int				buff;
	int				i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
		{
			buff = array[i];
			array[i] = array[i + 1];
			array[i + 1] = buff;
			i = -1;
		}
		i++;
	}
	return (array);
}

int					find_pivot(t_ps_list *lst, int len)
{
	t_ps_list		*i;
	int				*array;
	int				j;

	j = 0;
	array = malloc(sizeof(int) * len);
	i = lst;
	while (i)
	{
		array[j] = i->num;
		i = i->next;
		j++;
	}
	array = ft_sort_array(array, len);
	j = array[len / 2];
	free(array);
	return (j);
}

t_ps_list			*add_to_lst(t_ps_list *first, int num)
{
	t_ps_list		*lst;
	t_ps_list		*add;

	lst = first;
	add = (t_ps_list *)malloc(sizeof(t_ps_list));
	add->num = num;
	add->next = NULL;
	if (first != NULL)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = add;
	}
	else
		first = add;
	return (first);
}
