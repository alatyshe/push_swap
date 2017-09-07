/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						main(int argc, char **argv)
{
	t_ps_main			*main;
	t_ps_info			*info;

	if (argc < 2)
		ft_errors();
	else
	{
		info = info_lst();
		main = fill_struct(argc - 1, argv + 1, info);
		if (main->stack_a != NULL)
		{
			if (!check_for_repeat_int(main))
			{
				info->a_len = main->stack_a_size;
				check_for_sort(main) ? stack_a_recursion(main, info) : 0;
				main->c == 1 ? print_main(main) : 0;
			}
			else
				ft_errors();
		}
		free_main(main);
		free_info(info);
	}
	return (0);
}
