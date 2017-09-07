/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int					len_array(char **str)
{
	int		i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

int					check_for_num(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]) && (str[i] != '-' && !ft_isblank(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int					check_sort(t_ps_main *main)
{
	t_ps_list		*stack_a;

	stack_a = main->stack_a;
	if (main->stack_a != NULL && main->stack_b == NULL)
	{
		while (stack_a->next)
		{
			if (stack_a->num > stack_a->next->num)
				return (0);
			stack_a = stack_a->next;
		}
	}
	else
		return (0);
	return (1);
}
