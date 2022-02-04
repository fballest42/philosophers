/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chk_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:57:10 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:08:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps	*init_ps(t_ps *ps, int argc, char **argv)
{
	ps = ft_calloc(1, sizeof (t_ps));
	ps->argc = argc;
	ps->argv = argv;
	ps->checker = ft_strdup("");
	return (ps);
}

int	ft_isd_s(int chr)
{
	return ((chr >= 48 && chr <= 57) || chr == 32);
}

int	fn_chk_ok(t_ps *ps)
{
	int		cnt;
	int		cnt1;
	int		sign;

	cnt = 0;
	cnt1 = 0;
	sign = 0;
	while (++cnt < ps->argc)
	{
		while (ps->argv[cnt][cnt1])
		{
			sign = ((int)ps->argv[cnt][cnt1] == 43 || \
				(int) ps->argv[cnt][cnt1] == 45);
			if (ft_isd_s((int)ps->argv[cnt][cnt1]) == 0 && sign == 0)
				return (-1);
			if (sign == 1 && (ft_isd_s((int)ps->argv[cnt][cnt1 + 1]) == 0 || \
				(int)ps->argv[cnt][cnt1 + 1] == 32))
				return (-1);
			cnt1++;
		}
		cnt1 = 0;
	}
	return (0);
}

void	count_word(char const *str, char chr, t_ps *ps)
{
	int		swtch;

	swtch = 0;
	while (*str != 0)
	{
		if (swtch == 1 && *str == chr)
			swtch = 0;
		if (swtch == 0 && *str != chr)
		{
			swtch = 1;
			ps->cnt_n++;
		}
		str++;
	}
}

void	fn_cnt_n(t_ps *ps)
{
	int		cnt;

	cnt = 0;
	while (++cnt < ps->argc)
	{
		count_word(ps->argv[cnt], ' ', ps);
	}
	ps->mv.cnt_a = ps->cnt_n;
	ps->mv.cnt_b = 0;
}
