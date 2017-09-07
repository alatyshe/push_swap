/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**	ra : rotate a - shift up all elements of stack a by 1.
**	The first element becomes the last one.
**
**	rb : rotate b - shift up all elements of stack b by 1.
**	The first element becomes the last one.
**
**	rr : ra and rb at the same time.
*/

void				ra_func(t_ps_main *main, int print)
{
	t_ps_list		*last;
	t_ps_list		*first;

	if (main->stack_a != NULL)
	{
		first = main->stack_a;
		main->stack_a = main->stack_a->next;
		first->next = NULL;
		last = main->stack_a;
		while (last->next)
		{
			last = last->next;
		}
		last->next = first;
		if (print)
		{
			main->v == 1 ? print_main(main) : 0;
			ft_putstr("ra\n");
			main->len++;
		}
	}
}

void				rb_func(t_ps_main *main, int print)
{
	t_ps_list		*last;
	t_ps_list		*first;

	if (main->stack_b != NULL)
	{
		first = main->stack_b;
		main->stack_b = main->stack_b->next;
		first->next = NULL;
		last = main->stack_b;
		while (last->next)
		{
			last = last->next;
		}
		last->next = first;
		if (print)
		{
			main->v == 1 ? print_main(main) : 0;
			ft_putstr("rb\n");
			main->len++;
		}
	}
}

void				rr_func(t_ps_main *main, int print)
{
	rb_func(main, 0);
	ra_func(main, 0);
	if (print)
	{
		main->v == 1 ? print_main(main) : 0;
		ft_putstr("rr\n");
		main->len++;
	}
}
