/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_print_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

void				func_for_print_stack(t_ps_list *stack_in)
{
	t_ps_list		*stack;

	stack = stack_in;
	if (stack_in != NULL)
	{
		while (stack)
		{
			ft_putnbr_fd(stack->num, 2);
			stack = stack->next;
		}
	}
}

static void			print_stack_a(t_ps_main *main)
{
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd("STACK A ", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("STACK_A SIZE : ", 2);
	ft_putnbr_fd(main->stack_a_size, 2);
	ft_putstr_fd("\n", 2);
	func_for_print_stack(main->stack_a);
}

static void			print_stack_b(t_ps_main *main)
{
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("STACK B ", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("STACK_B SIZE : ", 2);
	ft_putnbr_fd(main->stack_b_size, 2);
	ft_putstr_fd("\n", 2);
	func_for_print_stack(main->stack_b);
}

void				print_main(t_ps_main *main)
{
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd("NUM OF ITERATIONS : ", 2);
	ft_putnbr_fd(main->len, 2);
	ft_putstr_fd(RESET, 2);
	print_stack_a(main);
	print_stack_b(main);
	ft_putstr_fd("\n\n", 2);
}
