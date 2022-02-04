/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:06:26 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:13:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fn_clean(t_ps *ps)
{
	free (ps->a);
	free (ps->b);
	free (ps->tmp);
	ft_free(ps->checker);
}

void	push_swap(t_ps *ps)
{
	if (ps->cnt_n == 2)
		fn_short_two(ps);
	if (ps->cnt_n == 3)
		fn_short_tree(ps);
	if (ps->cnt_n == 4 || ps->cnt_n == 5)
		fn_short_five(ps, 1);
	if (ps->cnt_n > 5)
		fn_short_max(ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = NULL;
	ps = init_ps(ps, argc, argv);
	if (argc <= 1)
		return (0);
	if (fn_chk_ok(ps) != 0)
		ft_msgerror("Bad Parameters.", -1);
	fn_cnt_n(ps);
	ps_strg_ab(ps);
	chk_repeat(ps);
	if (check_shorted(ps) == -1)
		return (0);
	push_swap(ps);
	printf("%s", ps->checker);
	fn_clean(ps);
	return (0);
}
