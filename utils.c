/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/03 14:41:48 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_status_show(char *str, int i, t_hilos *hilo)
{
	unsigned int	time;

	// pthread_mutex_lock(&hilo->general);
	time = now() - hilo->start_time;
	printf("%u - Philosopher Nº %d %s \n", time, i, str);
	// pthread_mutex_unlock(&hilo->general);
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

void	ft_bzero(void *str, size_t n)
{
	char		*c;
	size_t		i;

	c = (char *)str;
	i = 0;
	while (i < n)
	{
		*c = '\0';
		c++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}
