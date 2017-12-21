/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define BLACK   "\x1b[37m"
# define RESET   "\x1b[0m"

# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct		s_ps_list
{
	intmax_t			num;
	struct s_ps_list	*next;
}					t_ps_list;

typedef struct		s_ps_main
{
	t_ps_list			*stack_a;
	t_ps_list			*stack_b;
	int					stack_a_size;
	int					stack_b_size;
	int					len;
	int					v;
	int					c;
}					t_ps_main;
/*
**	swap directory
*/
void				pa_func(t_ps_main *main, int print);
void				pb_func(t_ps_main *main, int print);
void				sa_func(t_ps_main *main, int print);
void				sb_func(t_ps_main *main, int print);
void				ss_func(t_ps_main *main, int print);
void				rra_func(t_ps_main *main, int print);
void				rrb_func(t_ps_main *main, int print);
void				rrr_func(t_ps_main *main, int print);
void				ra_func(t_ps_main *main, int print);
void				rb_func(t_ps_main *main, int print);
void				rr_func(t_ps_main *main, int print);
/*
**	create_struct.c
*/
t_ps_list			*stack_lst(void);
t_ps_main			*main_lst(void);
/*
**	get_info.c
*/
t_ps_list			*stack_a(int from, int argc, char **argv);
t_ps_main			*fill_struct(int argc, char **argv);
/*
**	other.c
*/
int					len_array(char **str);
int					check_for_num(char *str);
int					check_sort(t_ps_main *main);
/*
**	checking.c
*/
int					check_for_repeat_int(t_ps_main *main);
int					check_for_alpha(int from, int argc, char **argv);
int					ft_errors(void);
int					check_flags(t_ps_main *main, int argc, char **argv);
/*
**	for_free.c
*/
void				func_for_free(t_ps_list *stack);
void				free_main(t_ps_main *main);
/*
**	read.c
*/
int					ft_for_read(int const fd, char **line, int delete);
/*
**	for_print_func.c
*/
void				print_main(t_ps_main *main);
void				func_for_print_stack(t_ps_list *stack_in);

#endif
