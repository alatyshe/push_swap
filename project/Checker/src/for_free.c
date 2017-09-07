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

#include "../checker.h"

void				func_for_free(t_ps_list *stack)
{
	t_ps_list		*next_elem;
	t_ps_list		*first_elem;

	if (stack != NULL)
	{
		first_elem = stack;
		if (first_elem->next != NULL)
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
			free(first_elem);
	}
}

void				free_main(t_ps_main *main)
{
	func_for_free(main->stack_a);
	func_for_free(main->stack_b);
	free(main);
}
