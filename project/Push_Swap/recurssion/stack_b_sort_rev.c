/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sort_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**	stack_b_sort_rev_loop_check - checking number(more or less than pivot)
**									IN loop;
**	stack_b_sort_rev_check 		- checking number(more or less than pivot)
**									AFTER loop;
**	stack_b_sort_rev			- variation of stack_b_sort func but in
**									reverse realisation;
**	func_for_sort_b				- func for sort 3 or less elem in stack
**									(get this info from general_info);
*/

static void			stack_b_sort_rev_loop_check(t_ps_main *main,
	t_ps_info *info_next, int pivot)
{
	if (info_next->a_len == 0 && main->stack_b->num + 1 == main->stack_a->num)
	{
		pa_func(main, 1);
		if (main->stack_b_size > 1)
			rrb_func(main, 1);
	}
	else if (main->stack_b->num > pivot)
	{
		info_next->stack_a = add_to_lst(info_next->stack_a, main->stack_b->num);
		pa_func(main, 1);
		rrb_func(main, 1);
		info_next->a_len++;
	}
	else
	{
		info_next->stack_b = add_to_lst(info_next->stack_b, main->stack_b->num);
		rrb_func(main, 1);
		info_next->b_len++;
	}
}

static void			stack_b_sort_rev_check(t_ps_main *main,
	t_ps_info *info_next, int pivot)
{
	if (info_next->a_len == 0 && main->stack_b->num + 1 == main->stack_a->num)
		pa_func(main, 1);
	else if (main->stack_b->num > pivot)
	{
		info_next->stack_a = add_to_lst(info_next->stack_a, main->stack_b->num);
		pa_func(main, 1);
		info_next->a_len++;
	}
	else
	{
		info_next->stack_b = add_to_lst(info_next->stack_b, main->stack_b->num);
		info_next->b_len++;
	}
}

void				stack_b_sort_rev(t_ps_main *main, t_ps_info *general_info)
{
	int				pivot;
	t_ps_info		*info_next;

	info_next = info_lst();
	if (general_info->b_len > 3)
	{
		pivot = find_pivot(general_info->stack_b, general_info->b_len);
		while (general_info->b_position--)
			stack_b_sort_rev_loop_check(main, info_next, pivot);
		stack_b_sort_rev_check(main, info_next, pivot);
		stack_a_sort(main, info_next);
		stack_b_sort(main, info_next);
	}
	else
		func_for_rev_b(main, general_info);
	free_info(info_next);
}

void				func_for_sort_b(t_ps_main *main, t_ps_info *general_info)
{
	if (general_info->b_len == 3)
		sort_three_elem_b(main, general_info);
	else if (general_info->b_len == 2)
		sort_two_elem_b(main, general_info);
	else if (general_info->b_len == 1)
		pa_func(main, 1);
}

void				func_for_rev_b(t_ps_main *main, t_ps_info *general_info)
{
	if (general_info->b_position > 0)
	{
		if (general_info->b_position >= 2 && general_info->b_len == 3)
			sort_three_elem_b_rev(main, general_info);
		else if (general_info->b_len >= 1 && main->stack_b_size > 1)
		{
			while (general_info->b_position > 0)
			{
				rrb_func(main, 1);
				general_info->b_position--;
			}
			func_for_sort_b(main, general_info);
		}
		else
			pa_func(main, 1);
	}
	else
		func_for_sort_b(main, general_info);
}
