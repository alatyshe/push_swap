/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sort_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	stack_a_sort_rev_loop_check - checking number(more or less than pivot)
**									IN loop;
**	stack_a_sort_rev_check 		- checking number(more or less than pivot)
**									AFTER loop;
**	stack_a_sort_rev			- variation of stack_a_sort func but in
**									reverse realisation;
**	func_for_sort_a				- func for sort 3 or less elem in stack
**									(get this info from general_info);
*/

static void			stack_a_sort_rev_loop_check(t_ps_main *main,
	t_ps_info *info_next, int pivot)
{
	if (info_next->a_len == 0 &&
			main->stack_a->num + 1 == main->stack_a->next->num)
		rra_func(main, 1);
	else if (main->stack_a->num < pivot)
	{
		info_next->stack_b = add_to_lst(info_next->stack_b, main->stack_a->num);
		pb_func(main, 1);
		rra_func(main, 1);
		info_next->b_len++;
	}
	else
	{
		info_next->stack_a = add_to_lst(info_next->stack_a, main->stack_a->num);
		rra_func(main, 1);
		info_next->a_len++;
	}
}

static void			stack_a_sort_rev_check(t_ps_main *main,
	t_ps_info *info_next, int pivot)
{
	if (info_next->a_len == 0 &&
			main->stack_a->num + 1 == main->stack_a->next->num)
		;
	else if (main->stack_a->num < pivot)
	{
		info_next->stack_b = add_to_lst(info_next->stack_b, main->stack_a->num);
		pb_func(main, 1);
		info_next->b_len++;
	}
	else
	{
		info_next->stack_a = add_to_lst(info_next->stack_a, main->stack_a->num);
		info_next->a_len++;
	}
}

void				stack_a_sort_rev(t_ps_main *main, t_ps_info *general_info)
{
	int				i;
	int				pivot;
	t_ps_info		*info_next;

	i = 0;
	info_next = info_lst();
	if (general_info->a_len > 3)
	{
		pivot = find_pivot(general_info->stack_a, general_info->a_len);
		while (general_info->a_position--)
			stack_a_sort_rev_loop_check(main, info_next, pivot);
		stack_a_sort_rev_check(main, info_next, pivot);
		stack_a_sort(main, info_next);
		stack_b_sort(main, info_next);
	}
	else
		func_for_sort_a(main, general_info);
	free_info(info_next);
}

void				func_for_sort_a(t_ps_main *main, t_ps_info *general_info)
{
	if (general_info->a_position >= 2 && general_info->a_len == 3)
		sort_three_elem_a_rev(main, general_info);
	else if (general_info->a_len <= 3)
	{
		func_for_rev_a(main, general_info);
		if (general_info->a_len == 3)
			sort_three_elem_a(main);
		else if (general_info->a_len == 2)
			sort_two_elem_a(main);
	}
}

void				func_for_rev_a(t_ps_main *main, t_ps_info *general_info)
{
	if (general_info->a_position > 0)
		while (general_info->a_position > 0)
		{
			rra_func(main, 1);
			general_info->a_position--;
		}
}
