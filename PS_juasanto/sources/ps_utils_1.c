/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  juasanto <juasanto@student.42madrid.c     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:13:13 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:08:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fn_rot_rev_ab(t_ps *ps, int action)
{
	int		tmp;

	if (action == 1 || action == 3)
	{
		ps->mv.cnt_a--;
		tmp = ps->a[ps->mv.cnt_a];
		fn_down_ab(ps, 1);
		ps->a[0] = tmp;
		if (action == 1)
			ps->checker = ft_strjoin_clean(ps->checker, "rra\n", 1);
	}
	if (action == 2 || action == 3)
	{
		ps->mv.cnt_b--;
		tmp = ps->b[ps->mv.cnt_b];
		fn_down_ab(ps, 2);
		ps->b[0] = tmp;
		if (action == 2)
			ps->checker = ft_strjoin_clean(ps->checker, "rrb\n", 1);
	}
	if (action == 3)
		ps->checker = ft_strjoin_clean(ps->checker, "rrr\n", 1);
	return (ps->cnt_chk++);
}

int	check_shorted(t_ps *ps)
{
	int		cnt;

	cnt = -1;
	fn_find_max(ps, 1);
	fn_find_min(ps, 1);
	while (++cnt < ps->cnt_n - 1)
	{
		if (ps->a[cnt] > ps->a[cnt + 1])
			return (0);
	}
	return (-1);
}

void	fn_find_min(t_ps *ps, int action)
{
	int	tmp;
	int	cnt;

	cnt = -1;
	tmp = 0;
	if (action == 1 || action == 3)
	{
		tmp = ps->a[0];
		while (++cnt < ps->mv.cnt_a)
			if (tmp > ps->a[cnt])
				tmp = ps->a[cnt];
		ps->mv.min_a = tmp;
	}
	cnt = -1;
	if (action == 2 || action == 3)
	{
		tmp = ps->b[0];
		while (++cnt < ps->mv.cnt_b)
			if (tmp > ps->b[cnt])
				tmp = ps->b[cnt];
		ps->mv.min_b = tmp;
	}
}

void	fn_find_max(t_ps *ps, int action)
{
	int	tmp;
	int	cnt;

	cnt = -1;
	tmp = 0;
	if (action == 1 || action == 3)
	{
		tmp = ps->a[0];
		while (++cnt < ps->mv.cnt_a)
			if (tmp < ps->a[cnt])
				tmp = ps->a[cnt];
		ps->mv.max_a = tmp;
	}
	cnt = -1;
	if (action == 2 || action == 3)
	{
		tmp = ps->b[0];
		while (++cnt < ps->mv.cnt_b)
			if (tmp < ps->b[cnt])
				tmp = ps->b[cnt];
		ps->mv.max_b = tmp;
	}
}
