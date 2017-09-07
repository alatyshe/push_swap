/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elems_rev_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void			b_first_var(t_ps_main *main)
{
	pa_func(main, 1);
	rrb_func(main, 1);
	pa_func(main, 1);
	if (main->stack_b_size > 1)
		rrb_func(main, 1);
	pa_func(main, 1);
}

static void			b_second_var(t_ps_main *main)
{
	pa_func(main, 1);
	rrb_func(main, 1);
	rrb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
}

static void			b_third_var(t_ps_main *main)
{
	rrb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
	if (main->stack_b_size > 1)
		rrb_func(main, 1);
	pa_func(main, 1);
}

static void			prepare_func(t_ps_main *main, t_ps_info *info,
	int *second_b, int *third_b)
{
	while (info->b_position > 0)
	{
		rrb_func(main, 0);
		info->b_position--;
		if (info->b_position == 1)
			*second_b = main->stack_b->num;
		else
			*third_b = main->stack_b->num;
	}
	while (info->b_position < 2)
	{
		rb_func(main, 0);
		info->b_position++;
	}
}

void				sort_three_elem_b_rev(t_ps_main *main, t_ps_info *info)
{
	int		first_b;
	int		second_b;
	int		third_b;

	if (info->b_position == 3 && info->b_position--)
		rrb_func(main, 1);
	first_b = main->stack_b->num;
	prepare_func(main, info, &second_b, &third_b);
	if (first_b > second_b && second_b > third_b)
		b_first_var(main);
	else if (first_b > third_b && third_b > second_b)
		b_second_var(main);
	else if (second_b > first_b && first_b > third_b)
		b_third_var(main);
	else if (second_b > third_b && third_b > first_b)
		b_fourth_var(main);
	else if (third_b > second_b && second_b > first_b)
		b_fifth_var(main);
	else if (third_b > first_b && first_b > second_b)
		b_six_var(main);
}
