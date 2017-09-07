/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
# include "../libft/libft.h"
# include <unistd.h>

typedef struct		s_ps_list
{
	intmax_t			num;
	struct s_ps_list	*next;
}					t_ps_list;

typedef struct		s_ps_info
{
	int					a_len;
	int					b_len;
	int					a_position;
	int					b_position;
	t_ps_list			*stack_a;
	t_ps_list			*stack_b;
}					t_ps_info;

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
**	sort directory
*/
void				sort_three_elem_a_rev(t_ps_main *main, t_ps_info *info);
void				a_fourth_var(t_ps_main *main);
void				a_fifth_var(t_ps_main *main);
void				a_six_var(t_ps_main *main);
void				sort_three_elem_a(t_ps_main *main);
void				sort_two_elem_a(t_ps_main *main);
void				sort_three_elem_b_rev(t_ps_main *main, t_ps_info *info);
void				b_fourth_var(t_ps_main *main);
void				b_fifth_var(t_ps_main *main);
void				b_six_var(t_ps_main *main);
void				sort_two_elem_b(t_ps_main *main, t_ps_info *info);
void				sort_three_elem_b(t_ps_main *main, t_ps_info *info);
int					b_fourth(t_ps_main *main);
int					b_fifth(t_ps_main *main);
/*
**	other directory
*/
int					check_for_repeat_int(t_ps_main *main);
int					check_for_alpha(int from, int argc, char **argv);
int					len_array(char **str);
int					check_for_num(char *str);
int					ft_errors(void);
int					check_for_sort(t_ps_main *main);
t_ps_main			*fill_struct(int argc, char **argv, t_ps_info *info);
int					check_flags(t_ps_main *main, int argc, char **argv);
t_ps_list			*stack_a(int from, int argc, char **argv, t_ps_info *info);
void				print_info(t_ps_info *info);
void				print_main(t_ps_main *main);
void				func_for_print_stack(t_ps_list *stack_in, char *color);
void				func_for_free(t_ps_list *stack);
void				free_main(t_ps_main *main);
void				free_info(t_ps_info *info);
int					*ft_sort_array(int *array, int len);
int					find_pivot(t_ps_list *lst, int len);
t_ps_list			*add_to_lst(t_ps_list *first, int num);
t_ps_main			*main_lst(void);
t_ps_info			*info_lst(void);
t_ps_list			*stack_lst(void);
/*
**	stack_a_recursion.c
*/
void				stack_a_recursion(t_ps_main *main, t_ps_info *info);
void				sort_three_elem_stack_a_recursion(t_ps_main *main);
/*
**	stack_b_sort.c
*/
void				stack_b_sort(t_ps_main *main, t_ps_info *general_info);
/*
**	stack_b_sort_rev.c
*/
void				stack_b_sort_rev(t_ps_main *main, t_ps_info *general_info);
void				func_for_sort_b(t_ps_main *main, t_ps_info *general_info);
void				func_for_rev_b(t_ps_main *main, t_ps_info *general_info);
/*
**	stack_a_sort.c
*/
void				stack_a_sort(t_ps_main *main, t_ps_info *general_info);
/*
**	stack_a_sort_rev.c
*/
void				stack_a_sort_rev(t_ps_main *main, t_ps_info *general_info);
void				func_for_rev_a(t_ps_main *main, t_ps_info *general_info);
void				func_for_sort_a(t_ps_main *main, t_ps_info *general_info);

#endif
