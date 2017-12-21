/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	pa : push a - take the first element at the top of b
**	and put it at the top of a. Do nothing if b is empty.
**
**	pb : push b - take the first element at the top of a
**	and put it at the top of b. Do nothing if a is empty.
*/

void				pa_func(t_ps_main *main, int print)
{
	t_ps_list		*a;

	if (main->stack_b != NULL)
	{
		a = main->stack_b;
		main->stack_b = main->stack_b->next;
		a->next = main->stack_a;
		main->stack_a = a;
		main->stack_a_size++;
		main->stack_b_size--;
		if (print)
		{
			main->v == 1 ? print_main(main) : 0;
			main->len++;
			ft_putstr("pa\n");
		}
	}
}

void				pb_func(t_ps_main *main, int print)
{
	t_ps_list		*b;

	if (main->stack_a != NULL)
	{
		b = main->stack_a;
		main->stack_a = main->stack_a->next;
		b->next = main->stack_b;
		main->stack_b = b;
		main->stack_a_size--;
		main->stack_b_size++;
		if (print)
		{
			main->v == 1 ? print_main(main) : 0;
			main->len++;
			ft_putstr("pb\n");
		}
	}
}
