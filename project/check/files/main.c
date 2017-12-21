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

#include "../headers/checker.h"

int					find_commands(t_ps_main *main, char *line)
{
	if (!ft_strcmp("sa", line))
		sa_func(main, 0);
	else if (!ft_strcmp("sb", line))
		sb_func(main, 0);
	else if (!ft_strcmp("ss", line))
		ss_func(main, 0);
	else if (!ft_strcmp("pa", line))
		pa_func(main, 0);
	else if (!ft_strcmp("pb", line))
		pb_func(main, 0);
	else if (!ft_strcmp("ra", line))
		ra_func(main, 0);
	else if (!ft_strcmp("rb", line))
		rb_func(main, 0);
	else if (!ft_strcmp("rr", line))
		rr_func(main, 0);
	else if (!ft_strcmp("rra", line))
		rra_func(main, 0);
	else if (!ft_strcmp("rrb", line))
		rrb_func(main, 0);
	else if (!ft_strcmp("rrr", line))
		rrr_func(main, 0);
	else
		return (0);
	return (1);
}

static int			read_commands(t_ps_main *main)
{
	char			*line;

	while (ft_for_read(0, &line, 0))
	{
		if (find_commands(main, line))
			free(line);
		else if (ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		else
		{
			free_main(main);
			free(line);
			ft_for_read(0, &line, 1);
			return (ft_errors());
		}
	}
	ft_for_read(0, &line, 1);
	check_sort(main) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	free_main(main);
	return (0);
}

int					main(int argc, char **argv)
{
	t_ps_main		*main;

	if (argc < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
	{
		main = fill_struct(argc - 1, argv + 1);
		if (main->stack_a != NULL)
		{
			if (!check_for_repeat_int(main))
				read_commands(main);
			else
				ft_errors();
		}
		else
			return (0);
	}
	return (0);
}
