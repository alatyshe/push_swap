/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void				func_for_free(t_ps_list *stack)
{
	t_ps_list		*next_elem;
	t_ps_list		*first_elem;

	if (stack != NULL)
	{
		first_elem = stack;
		if (stack->next != NULL)
		{
			next_elem = first_elem->next;
			while (first_elem)
			{
				next_elem = first_elem->next;
				free(first_elem);
				first_elem = next_elem;
			}
		}
		else
			free(stack);
	}
}

void				free_main(t_ps_main *main)
{
	func_for_free(main->stack_a);
	func_for_free(main->stack_b);
	free(main);
}

void				free_info(t_ps_info *info)
{
	func_for_free(info->stack_a);
	func_for_free(info->stack_b);
	free(info);
}
