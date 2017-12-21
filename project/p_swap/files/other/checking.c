/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int					check_for_repeat_int(t_ps_main *main)
{
	t_ps_list		*first;
	t_ps_list		*second;
	int				i;

	first = main->stack_a;
	second = main->stack_a;
	i = 0;
	while (first)
	{
		second = main->stack_a;
		while (second)
		{
			if (second->num == first->num)
				i++;
			if (i > 1)
				return (1);
			second = second->next;
		}
		i = 0;
		first = first->next;
	}
	return (0);
}

int					check_for_alpha(int from, int argc, char **argv)
{
	while (from < argc)
	{
		if (!check_for_num(argv[from]))
			return (ft_errors());
		from++;
	}
	return (1);
}
