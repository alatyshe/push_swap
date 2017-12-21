/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_ps_main			*main_lst(void)
{
	t_ps_main		*main;

	main = malloc(sizeof(t_ps_main));
	main->stack_a = NULL;
	main->stack_b = NULL;
	main->stack_a_size = 0;
	main->stack_b_size = 0;
	main->len = 0;
	main->v = 0;
	main->c = 0;
	return (main);
}

t_ps_info			*info_lst(void)
{
	t_ps_info		*info;

	info = malloc(sizeof(t_ps_info));
	info->a_len = 0;
	info->b_len = 0;
	info->a_position = 0;
	info->b_position = 0;
	info->stack_a = NULL;
	info->stack_b = NULL;
	return (info);
}

t_ps_list			*stack_lst(void)
{
	t_ps_list		*lst;

	lst = (t_ps_list *)malloc(sizeof(t_ps_list));
	lst->next = NULL;
	return (lst);
}
