/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:13:23 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:08:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** Libraries
*/
# include <stdio.h>
# include <unistd.h>
# include "../Libft/includes/libft.h"

/*
** Structures
*/

typedef struct s_mv
{
	int		cnt_a;
	int		cnt_b;
	int		min_a;
	int		max_a;
	int		min_b;
	int		max_b;
}			t_mv;

/*
** Main Structure
*/
typedef struct s_ps
{
	int		argc;
	char	**argv;
	int		*a;
	int		*b;
	int		*tmp;
	int		cnt_n;
	int		cnt_g;
	char	*checker;
	int		cnt_chk;
	t_mv	mv;
}			t_ps;

/*
** Funtions
*/
t_ps	*init_ps(t_ps *ps, int argc, char **argv);
int		ft_isd_s(int chr);
int		fn_chk_ok(t_ps *ps);
void	count_word(char const *str, char chr, t_ps *ps);
void	fn_cnt_n(t_ps *ps);
int		fn_chk_int(long long int chk);
void	chk_repeat(t_ps *ps);
void	fn_str_num(t_ps *ps, int cnt);
void	ps_strg_ab(t_ps *ps);
void	fn_up_ab(t_ps *ps, int action);
void	fn_down_ab(t_ps *ps, int action);
int		fn_swap_ab(t_ps *ps, int swap);
void	pb(t_ps *ps);
int		fn_push_ab(t_ps *ps, int push);
void	pa(t_ps *ps);
int		fn_rot_ab(t_ps *ps, int action);
void	ra(t_ps *ps);
int		fn_rot_rev_ab(t_ps *ps, int action);
int		check_shorted(t_ps *ps);
void	push_swap(t_ps *ps);
void	fn_find_min(t_ps *ps, int action);
void	fn_find_max(t_ps *ps, int action);
void	fn_short_two(t_ps *ps);
void	fn_short_tree(t_ps *ps);
void	fn_short_five(t_ps *ps, int fn);
void	fn_short_max(t_ps *ps);

#endif
