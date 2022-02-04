/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mv_ab_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:18:59 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:21:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fn_up_ab(t_ps *ps, int action)
{
	int		cnt;

	cnt = -1;
	if (action == 1)
	{
		while (++cnt <= ps->mv.cnt_a)
			ps->a[cnt] = ps->a[cnt + 1];
		ps->a[cnt] = 0;
		ps->mv.cnt_a--;
	}
	if (action == 2)
	{
		while (++cnt <= ps->mv.cnt_b)
			ps->b[cnt] = ps->b[cnt + 1];
		ps->b[cnt] = 0;
		ps->mv.cnt_b--;
	}
}
/*
 * 1 - a, 2 - b.
 */

void	fn_down_ab(t_ps *ps, int action)
{
	int		cnt;

	if (action == 1)
	{
		cnt = ps->mv.cnt_a++;
		while (cnt != 0)
		{
			ps->a[cnt] = ps->a[cnt - 1];
			cnt--;
		}
	}
	if (action == 2)
	{
		cnt = ps->mv.cnt_b++;
		while (cnt != 0)
		{
			ps->b[cnt] = ps->b[cnt - 1];
			cnt--;
		}
	}
}

/*
* swap=1 para A - sa, swap=2 para B - sb, swap=3 para AB - ss
*/

int	fn_swap_ab(t_ps *ps, int swap)
{
	int		tmp;

	if ((swap == 1 || swap == 3) && ps->mv.cnt_a > 1)
	{
		tmp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = tmp;
		if (swap == 1)
			ps->checker = ft_strjoin_clean(ps->checker, "sa\n", 1);
	}
	if ((swap == 2 || swap == 3) && ps->mv.cnt_b > 1)
	{
		tmp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = tmp;
		if (swap == 2)
			ps->checker = ft_strjoin_clean(ps->checker, "sb\n", 1);
	}
	if (swap == 3)
		ps->checker = ft_strjoin_clean(ps->checker, "ss\n", 1);
	return (ps->cnt_chk++);
}

/*
* push=1 de B a A - pa, push=2 de A a B - pb
*/

int	fn_push_ab(t_ps *ps, int push)
{
	if (push == 1 && ps->mv.cnt_b > 0)
	{
		fn_down_ab(ps, 1);
		ps->a[0] = ps->b[0];
		fn_up_ab(ps, 2);
		ps->checker = ft_strjoin_clean(ps->checker, "pa\n", 1);
	}
	if (push == 2 && ps->mv.cnt_a > 0)
	{
		fn_down_ab(ps, 2);
		ps->b[0] = ps->a[0];
		fn_up_ab(ps, 1);
		ps->checker = ft_strjoin_clean(ps->checker, "pb\n", 1);
	}
	return (ps->cnt_chk++);
}

int	fn_rot_ab(t_ps *ps, int action)
{
	int		tmp;

	if (action == 1 || action == 3)
	{
		tmp = ps->a[0];
		fn_up_ab(ps, 1);
		ps->a[ps->mv.cnt_a] = tmp;
		ps->mv.cnt_a++;
		if (action == 1)
			ps->checker = ft_strjoin_clean(ps->checker, "ra\n", 1);
	}
	if (action == 2 || action == 3)
	{
		tmp = ps->b[0];
		fn_up_ab(ps, 2);
		ps->b[ps->mv.cnt_b] = tmp;
		ps->mv.cnt_b++;
		if (action == 2)
			ps->checker = ft_strjoin_clean(ps->checker, "rb\n", 1);
	}
	if (action == 3)
		ps->checker = ft_strjoin_clean(ps->checker, "rr\n", 1);
	return (ps->cnt_chk++);
}
