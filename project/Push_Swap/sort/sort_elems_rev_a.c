/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elems_rev_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void			a_first_var(t_ps_main *main)
{
	pb_func(main, 1);
	rra_func(main, 1);
	rra_func(main, 1);
	sa_func(main, 1);
	pa_func(main, 1);
}

static void			a_second_var(t_ps_main *main)
{
	pb_func(main, 1);
	rra_func(main, 1);
	rra_func(main, 1);
	pa_func(main, 1);
}

static void			a_third_var(t_ps_main *main)
{
	rra_func(main, 1);
	rra_func(main, 1);
	sa_func(main, 1);
	ra_func(main, 1);
	sa_func(main, 1);
	rra_func(main, 1);
}

static void			prepare_func(t_ps_main *main, t_ps_info *info,
	int *second_b, int *third_b)
{
	while (info->a_position > 0)
	{
		rra_func(main, 0);
		info->a_position--;
		if (info->a_position == 1)
			*second_b = main->stack_a->num;
		else
			*third_b = main->stack_a->num;
	}
	while (info->a_position < 2)
	{
		ra_func(main, 0);
		info->a_position++;
	}
}

void				sort_three_elem_a_rev(t_ps_main *main, t_ps_info *info)
{
	int		first_b;
	int		second_b;
	int		third_b;

	if (info->a_position == 3 && info->a_position--)
		rra_func(main, 1);
	first_b = main->stack_a->num;
	prepare_func(main, info, &second_b, &third_b);
	if (first_b < second_b && second_b < third_b)
		a_first_var(main);
	else if (first_b < third_b && third_b < second_b)
		a_second_var(main);
	else if (second_b < first_b && first_b < third_b)
		a_third_var(main);
	else if (second_b < third_b && third_b < first_b)
		a_fourth_var(main);
	else if (third_b < second_b && second_b < first_b)
		a_fifth_var(main);
	else if (third_b < first_b && first_b < second_b)
		a_six_var(main);
}
