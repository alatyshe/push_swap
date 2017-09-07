/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int			b_first(t_ps_main *main)
{
	pa_func(main, 1);
	sb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
	return (3);
}

static int			b_second(t_ps_main *main)
{
	rb_func(main, 1);
	sb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
	main->stack_b_size > 1 ? rrb_func(main, 1) : pa_func(main, 1);
	return ((main->stack_b_size > 1) ? 2 : 3);
}

static int			b_third(t_ps_main *main)
{
	rb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
	main->stack_b_size > 1 ? rrb_func(main, 1) : pa_func(main, 1);
	return ((main->stack_b_size > 1) ? 2 : 3);
}

void				sort_three_elem_b(t_ps_main *main, t_ps_info *info)
{
	int		first_b;
	int		second_b;
	int		third_b;
	int		indicator_b;

	indicator_b = 3;
	first_b = main->stack_b->num;
	second_b = main->stack_b->next->num;
	third_b = main->stack_b->next->next->num;
	if (first_b > third_b && third_b > second_b)
		indicator_b -= b_first(main);
	else if (third_b > second_b && second_b > first_b)
		indicator_b -= b_second(main);
	else if (second_b > third_b && second_b > first_b && third_b > first_b)
		indicator_b -= b_third(main);
	else if (third_b > first_b && first_b > second_b)
		indicator_b -= b_fourth(main);
	else if (first_b > third_b && second_b > third_b && second_b > first_b)
		indicator_b -= b_fifth(main);
	while (indicator_b > 0)
	{
		pa_func(main, 1);
		indicator_b--;
	}
	info->b_len = 0;
}

void				sort_two_elem_b(t_ps_main *main, t_ps_info *info)
{
	int		first;
	int		second;

	first = main->stack_b->num;
	second = main->stack_b->next->num;
	if (first < second)
		sb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
	info->b_len = 0;
}
