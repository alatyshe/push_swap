/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**	rra : reverse rotate a - shift down all elements of stack a by 1.
**	The last element becomes the first one.
**
**	rrb : reverse rotate b - shift down all elements of stack b by 1.
**	The last element becomes the first one.
**
**	rrr : rra and rrb at the same time.
*/

void				rra_func(t_ps_main *main, int print)
{
	t_ps_list		*last;
	t_ps_list		*first;
	t_ps_list		*before;

	if (main->stack_a != NULL)
	{
		first = main->stack_a;
		last = main->stack_a;
		while (last->next)
		{
			before = last;
			last = last->next;
		}
		last->next = first;
		before->next = NULL;
		main->stack_a = last;
		if (print)
		{
			main->v == 1 ? print_main(main) : 0;
			ft_putstr("rra\n");
			main->len++;
		}
	}
}

void				rrb_func(t_ps_main *main, int print)
{
	t_ps_list		*last;
	t_ps_list		*first;
	t_ps_list		*before;

	if (main->stack_b != NULL)
	{
		first = main->stack_b;
		last = main->stack_b;
		while (last->next)
		{
			before = last;
			last = last->next;
		}
		before->next = NULL;
		last->next = first;
		main->stack_b = last;
		if (print)
		{
			main->v == 1 ? print_main(main) : 0;
			ft_putstr("rrb\n");
			main->len++;
		}
	}
}

void				rrr_func(t_ps_main *main, int print)
{
	rra_func(main, 0);
	rrb_func(main, 0);
	if (print)
	{
		main->v == 1 ? print_main(main) : 0;
		ft_putstr("rrr\n");
		main->len++;
	}
}
