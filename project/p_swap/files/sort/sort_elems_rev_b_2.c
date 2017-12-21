/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elems_rev_b_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void				b_fourth_var(t_ps_main *main)
{
	rrb_func(main, 1);
	pa_func(main, 1);
	rrb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
}

void				b_fifth_var(t_ps_main *main)
{
	rrb_func(main, 1);
	rrb_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
	pa_func(main, 1);
}

void				b_six_var(t_ps_main *main)
{
	rrb_func(main, 1);
	rrb_func(main, 1);
	pa_func(main, 1);
	rb_func(main, 1);
	pa_func(main, 1);
	if (main->stack_b_size > 1)
		rrb_func(main, 1);
	pa_func(main, 1);
}

int					b_fourth(t_ps_main *main)
{
	rb_func(main, 1);
	sb_func(main, 1);
	pa_func(main, 1);
	rrb_func(main, 1);
	return (1);
}

int					b_fifth(t_ps_main *main)
{
	sb_func(main, 1);
	pa_func(main, 1);
	return (1);
}
