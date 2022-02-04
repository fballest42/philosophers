/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:06:26 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:37:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_ps *ps)
{
	if (!ps->mv.cnt_a)
		return ;
	ps->b[ps->mv.cnt_b++] = ps->a[--ps->mv.cnt_a];
	ps->checker = ft_strjoin_clean(ps->checker, "pb\n", 1);
}

void	ra(t_ps *ps)
{
	int	i;
	int	c;

	i = 0;
	while (++i < ps->mv.cnt_a)
	{
		c = ps->a[ps->mv.cnt_a - i];
		ps->a[ps->mv.cnt_a - i] = ps->a[ps->mv.cnt_a - i - 1];
		ps->a[ps->mv.cnt_a - i - 1] = c;
	}
	ps->checker = ft_strjoin_clean(ps->checker, "ra\n", 1);
}

void	pa(t_ps *ps)
{
	if (!ps->mv.cnt_b)
		return ;
	ps->a[ps->mv.cnt_a++] = ps->b[--ps->mv.cnt_b];
	ps->checker = ft_strjoin_clean(ps->checker, "pa\n", 1);
}

void	fn_new_a(t_ps *ps)
{
	int		cnt;
	int		cnt_1;

	cnt_1 = 0;
	fn_find_max(ps, 1);
	fn_find_min(ps, 1);
	while (ps->mv.min_a <= ps->mv.max_a)
	{
		cnt = 0;
		while (cnt < ps->mv.cnt_a)
		{
			if (ps->mv.min_a == ps->a[cnt])
			{
				ps->tmp[cnt] = cnt_1++;
				ps->a[cnt] = ps->mv.max_a + 1;
			}
			cnt++;
		}
		ps->mv.min_a++;
	}
	cnt = 0;
	cnt_1 = ps->cnt_n -1;
	while (cnt < ps->cnt_n)
		ps->a[cnt++] = ps->tmp[cnt_1--];
}

void	fn_short_max(t_ps *ps)
{
	int		max_bits;
	int		cnt;
	int		cnt_1;

	fn_new_a(ps);
	fn_find_max(ps, 1);
	max_bits = 0;
	while ((ps->mv.max_a >> max_bits) != 0)
		++max_bits;
	cnt = -1;
	while (++cnt < max_bits)
	{
		cnt_1 = ps->mv.cnt_a;
		while (--cnt_1 >= 0)
		{
			if (((ps->a[ps->mv.cnt_a -1] >> cnt) & 1) == 0)
				pb(ps);
			else
				ra(ps);
		}
		while (ps->mv.cnt_b)
			pa(ps);
	}
}
