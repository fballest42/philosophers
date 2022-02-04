/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:47:51 by    juasanto       #+#    #+#             */
/*   Updated: 2022/01/10 11:22:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fn_short_two(t_ps *ps)
{
	if (ps->a[0] > ps->a[1])
		fn_swap_ab(ps, 1);
}

void	fn_short_tree(t_ps *ps)
{
	if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2] && ps->a[0] < ps->a[2])
		fn_swap_ab(ps, 1);
	else if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2] && ps->a[0] > ps->a[2])
		fn_rot_ab(ps, 1);
	else if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] > ps->a[2])
		fn_rot_rev_ab(ps, 1);
	else if (ps->a[0] > ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] > ps->a[2])
	{
		fn_swap_ab(ps, 1);
		fn_rot_rev_ab(ps, 1);
	}
	else if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] < ps->a[2])
	{
		fn_swap_ab(ps, 1);
		fn_rot_ab(ps, 1);
	}
}

int	fn_srch_min_x(t_ps *ps, int num_srch)
{
	int		cnt;
	int		cnt1;
	int		tmp;

	cnt = 0;
	cnt1 = 0;
	tmp = ps->a[cnt];
	while (++cnt < num_srch)
	{
		if (tmp > ps->a[cnt])
		{
			tmp = ps->a[cnt];
			cnt1 = cnt;
		}
	}
	return (cnt1);
}

void	fn_short_five_aux(t_ps *ps, int ctrl)
{
	int		cnt1;

	cnt1 = fn_srch_min_x(ps, ctrl);
	if (cnt1 == 1)
		fn_rot_ab(ps, 1);
	if (cnt1 == 2)
	{
		fn_rot_ab(ps, 1);
		fn_rot_ab(ps, 1);
	}
	if (cnt1 == 3)
	{
		if (ctrl == 5 && ps->cnt_n == 5)
			fn_rot_rev_ab(ps, 1);
		fn_rot_rev_ab(ps, 1);
	}
	if (cnt1 == 4)
		fn_rot_rev_ab(ps, 1);
	fn_push_ab(ps, 2);
	if (ps->mv.cnt_b < 2 && ps->cnt_n == 5)
		fn_short_five_aux(ps, 4);
}

void	fn_short_five(t_ps *ps, int fn)
{
	fn_short_five_aux(ps, 5);
	fn_short_tree(ps);
	if (fn == 1)
	{
		fn_push_ab(ps, 1);
		if (ps->cnt_n == 5)
			fn_push_ab(ps, 1);
	}
	else
	{
		fn_push_ab(ps, 2);
		fn_push_ab(ps, 2);
		fn_push_ab(ps, 2);
	}
}
