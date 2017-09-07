/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:48:08 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/27 17:48:09 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_atoi_base	- converting from any system to int
*/

char			ft_nulling_char(char c)
{
	int			clone;

	clone = c;
	if (c >= 'a' && c <= 'z')
		clone -= 32;
	return (clone);
}

int				ft_find_char(char find, int base)
{
	char			*str;
	int				i;
	char			a;

	i = 0;
	a = find;
	a = ft_nulling_char(a);
	str = "0123456789ABCDEF";
	while (str[i] && i < base)
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_check_len(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	if (i > 19)
		return (0);
	return (1);
}

void			ft_skip_zero(char **str)
{
	if (*(*str) == '-')
		(*str) += 1;
	while (*(*str) == '0' || *(*str) == '+')
		(*str) += 1;
}

intmax_t		ft_atoi_base(char *str, int base)
{
	intmax_t		i;
	int				k;
	int				minus;

	i = 0;
	k = 0;
	minus = 1;
	if (str[0] == '-')
		minus = -1;
	else if (str[0] == '+')
		minus = 1;
	ft_skip_zero(&str);
	if (!ft_check_len(str))
		return (minus == -1 ? INTMAX_MIN : INTMAX_MAX);
	while (str[k] != '\0' && ((str[k] != ' ' || str[k] != '\t')))
	{
		if ((ft_find_char(str[k], base)) > -1)
		{
			if (i == 0)
				i += ft_find_char(str[k++], base);
			else
				i = (i * base) + ft_find_char(str[k++], base);
		}
	}
	return (i * minus);
}
