/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

t_ps_main			*fill_struct(int argc, char **argv)
{
	t_ps_main		*main;
	int				from;

	main = main_lst();
	from = check_flags(main, argc, argv);
	main->stack_a_size = argc - from;
	if (check_for_alpha(from, argc, argv) != 0)
		main->stack_a = stack_a(from, argc, argv);
	return (main);
}

t_ps_list			*stack_a(int from, int argc, char **argv)
{
	t_ps_list		*stack_a;
	t_ps_list		*first_elem;
	int				i;

	i = from;
	while (from < argc)
	{
		if (i == from)
			first_elem = stack_lst();
		else
			stack_a->next = stack_lst();
		stack_a = (i == from) ? first_elem : stack_a->next;
		stack_a->num = ft_atoi_base(argv[from++], 10);
		if (stack_a->num > 2147483647 || stack_a->num < -2147483648)
		{
			ft_errors();
			func_for_free(first_elem);
			return (NULL);
		}
	}
	return (first_elem);
}
