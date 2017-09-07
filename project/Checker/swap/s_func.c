/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/*
**	sa : swap a - swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements).
**
**	sb : swap b - swap the first 2 elements at the top of stack b.
**	Do nothing if there is only one or no elements).
**
**	ss : sa and sb at the same time.
*/

void				sa_func(t_ps_main *main, int print)
{
	intmax_t		buf;
	t_ps_list		*a;

	a = main->stack_a;
	if (a != NULL && a->next != NULL)
	{
		buf = a->num;
		a->num = a->next->num;
		a->next->num = buf;
		if (print)
		{
			ft_putstr("sa\n");
			main->len++;
		}
	}
}

void				sb_func(t_ps_main *main, int print)
{
	intmax_t		buf;
	t_ps_list		*b;

	b = main->stack_b;
	if (b != NULL && b->next != NULL)
	{
		buf = b->num;
		b->num = b->next->num;
		b->next->num = buf;
		if (print)
		{
			ft_putstr("sb\n");
			main->len++;
		}
	}
}

void				ss_func(t_ps_main *main, int print)
{
	sa_func(main, 0);
	sb_func(main, 0);
	if (print)
	{
		ft_putstr("ss\n");
		main->len++;
	}
}
