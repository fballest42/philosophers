/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/14 12:08:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_status_show(char *str, int i, t_philos *p, int force)
{
	unsigned long		time;

	pthread_mutex_lock(&(p->dp->printer));
	time = now() - p->dp->init_time;
	if ((p->dp->alive == 0 && p->dp->eaten == 0) || force)
		printf("[%lu] - %d %s \n", time, i, str);
	pthread_mutex_unlock(&(p->dp->printer));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long int	ft_atolli(const char *str)
{
	int			sign;
	long int	res;

	sign = 0;
	res = 0;
	while ((*str == 32) || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		if (res < 9223372036854775807)
		{
			res = (res * 10) + (*str - '0');
			str++;
		}
		else
			return ((sign - 1) * 1);
	}
	if (sign == 1)
		return (-res);
	return (res);
}
