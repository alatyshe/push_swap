/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_recursion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void			less_than_pivot(t_ps_main *main, t_ps_info *info)
{
	info->stack_b = add_to_lst(info->stack_b, main->stack_a->num);
	info->b_len++;
	pb_func(main, 1);
}

static void			more_than_pivot(t_ps_main *main, t_ps_info *info_next,
	int *i)
{
	info_next->stack_a = add_to_lst(info_next->stack_a, main->stack_a->num);
	*i += 1;
	ra_func(main, 1);
}

void				stack_a_recursion(t_ps_main *main, t_ps_info *info)
{
	int				i;
	int				pivot;
	t_ps_info		*info_next;

	i = 0;
	info_next = info_lst();
	if (main->stack_a_size > 3)
	{
		pivot = find_pivot(info->stack_a, main->stack_a_size);
		while (i < main->stack_a_size && main->stack_a_size != 1)
		{
			if (main->stack_a->num <= pivot)
				less_than_pivot(main, info);
			else
				more_than_pivot(main, info_next, &i);
		}
		stack_a_recursion(main, info_next);
		stack_b_sort(main, info);
	}
	free_info(info_next);
	if (main->stack_a_size == 3)
		sort_three_elem_stack_a_recursion(main);
	else if (main->stack_a_size == 2)
		sort_two_elem_a(main);
}

void				sort_three_elem_stack_a_recursion(t_ps_main *main)
{
	int		first_a;
	int		second_a;
	int		third_a;

	first_a = main->stack_a->num;
	second_a = main->stack_a->next->num;
	third_a = main->stack_a->next->next->num;
	if (first_a < third_a && third_a < second_a)
	{
		ra_func(main, 1);
		sa_func(main, 1);
		rra_func(main, 1);
	}
	else if (third_a < second_a && second_a < first_a)
	{
		sa_func(main, 1);
		rra_func(main, 1);
	}
	else if (second_a < third_a && second_a < first_a && third_a < first_a)
		ra_func(main, 1);
	else if (third_a < first_a && first_a < second_a)
		rra_func(main, 1);
	else if (first_a < third_a && second_a < third_a && second_a < first_a)
		sa_func(main, 1);
}
