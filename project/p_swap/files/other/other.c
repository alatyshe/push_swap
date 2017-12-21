/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int					len_array(char **str)
{
	int				i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

int					check_for_num(char *str)
{
	int				i;
	int				j;
	int				len;
	int				dig;

	i = 0;
	j = 0;
	dig = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_isdigit(str[i]))
			dig++;
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		if ((str[i] == '-' || str[i] == '+') && i != 0)
			return (0);
		if (str[i] == '+' || str[i] == '-')
			j++;
		i++;
	}
	if (dig == 0 || j > 1)
		return (0);
	return (1);
}

int					ft_errors(void)
{
	ft_putstr("Error\n");
	return (0);
}

int					check_for_sort(t_ps_main *main)
{
	t_ps_list		*stack;

	stack = main->stack_a;
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
