/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void			a_first(t_ps_main *main)
{
	ra_func(main, 1);
	sa_func(main, 1);
	rra_func(main, 1);
}

static void			a_second(t_ps_main *main)
{
	sa_func(main, 1);
	ra_func(main, 1);
	sa_func(main, 1);
	rra_func(main, 1);
	sa_func(main, 1);
}

static void			a_third(t_ps_main *main)
{
	sa_func(main, 1);
	ra_func(main, 1);
	sa_func(main, 1);
	rra_func(main, 1);
}

void				sort_three_elem_a(t_ps_main *main)
{
	int		first_a;
	int		second_a;
	int		third_a;

	first_a = main->stack_a->num;
	second_a = main->stack_a->next->num;
	third_a = main->stack_a->next->next->num;
	if (first_a < third_a && third_a < second_a)
		a_first(main);
	else if (third_a < second_a && second_a < first_a)
		a_second(main);
	else if (second_a < third_a && second_a < first_a && third_a < first_a)
		a_third(main);
	else if (third_a < first_a && first_a < second_a)
	{
		ra_func(main, 1);
		sa_func(main, 1);
		rra_func(main, 1);
		sa_func(main, 1);
	}
	else if (first_a < third_a && second_a < third_a && second_a < first_a)
		sa_func(main, 1);
}

void				sort_two_elem_a(t_ps_main *main)
{
	int		first;
	int		second;

	first = main->stack_a->num;
	second = main->stack_a->next->num;
	if (first > second)
		sa_func(main, 1);
}
