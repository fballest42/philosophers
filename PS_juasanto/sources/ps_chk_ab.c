/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chk_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <juasanto <juasanto@student.42madrid.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:02 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:08:33 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freematrice(char ***matrice)
{
	int		i;

	i = -1;
	while ((*matrice)[++i])
		free((*matrice)[i]);
	free(*matrice);
}

int	fn_chk_int(long long int chk)
{
	int	intmax;
	int	intmin;

	intmax = 2147483647;
	intmin = -2147483648;
	if (chk > intmax || chk < intmin)
		return (-1);
	return (0);
}

void	chk_repeat(t_ps *ps)
{
	int		cnt;
	int		cnt1;

	cnt = 0;
	while (cnt < ps->cnt_n)
	{
		cnt1 = cnt + 1;
		while (cnt1 < ps->cnt_n)
			if (ps->a[cnt] == ps->a[cnt1++])
				ft_msgerror("Duplicated Number.", -1);
		cnt++;
	}
}

void	fn_str_num(t_ps *ps, int cnt)
{
	int			cnt1;
	long int	chk;
	char		**str_num;

	cnt1 = 0;
	str_num = NULL;
	str_num = ft_split(ps->argv[cnt], ' ');
	while (str_num[cnt1] != 0)
	{
		chk = ft_atoi(str_num[cnt1]);
		if (fn_chk_int(chk) == -1)
			ft_msgerror("INT max or min error.", -1);
		ps->a[ps->cnt_g++] = (int)chk;
		cnt1++;
		cnt++;
	}
	ft_freematrice(&str_num);
}

void	ps_strg_ab(t_ps *ps)
{
	int			cnt;
	long int	chk;

	cnt = 1;
	ps->a = ft_calloc(sizeof(int), ps->cnt_n + 1);
	ps->b = ft_calloc(sizeof(int), ps->cnt_n + 1);
	ps->tmp = ft_calloc(sizeof(int), ps->cnt_n + 1);
	while (cnt < ps->argc)
	{
		if (ft_strchr(ps->argv[cnt], 32) != NULL)
			fn_str_num(ps, cnt);
		else
		{
			chk = ft_atoi(ps->argv[cnt]);
			if (fn_chk_int(chk) == -1)
				ft_msgerror("INT max or min error.", -1);
			ps->a[ps->cnt_g++] = (int)chk;
		}
		cnt++;
	}
}
