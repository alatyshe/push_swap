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

#include "../../headers/push_swap.h"

t_ps_main			*fill_struct(int argc, char **argv, t_ps_info *info)
{
	t_ps_main		*main;
	int				from;

	main = main_lst();
	from = check_flags(main, argc, argv);
	main->stack_a_size = argc - from;
	if (check_for_alpha(from, argc, argv) != 0)
		main->stack_a = stack_a(from, argc, argv, info);
	return (main);
}

int					check_flags(t_ps_main *main, int argc, char **argv)
{
	int				i;

	i = 0;
	if (!ft_strcmp("-v", argv[0]) || !ft_strcmp("-c", argv[0]))
	{
		if (!ft_strcmp("-v", argv[0]))
			main->v = 1;
		else if (!ft_strcmp("-c", argv[0]))
			main->c = 1;
		i++;
	}
	if (argc > 1 && (!ft_strcmp("-v", argv[1]) || !ft_strcmp("-c", argv[1])))
	{
		if (!ft_strcmp("-v", argv[1]))
			main->v = 1;
		else if (!ft_strcmp("-c", argv[0]))
			main->c = 1;
		i++;
	}
	return (i);
}

t_ps_list			*stack_a(int from, int argc, char **argv, t_ps_info *info)
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
		info->stack_a = add_to_lst(info->stack_a, stack_a->num);
	}
	return (first_elem);
}
