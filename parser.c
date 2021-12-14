/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:33:17 by fballest          #+#    #+#             */
/*   Updated: 2021/12/14 13:33:53 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_print_error(char *err, int errnum, t_philo *philo)
{
	printf("Error : %s\n", err);
	free (philo);
	return (errnum);
}

int	ft_check_values(char **argv, int *i, t_philo *philo)
{
	if ((*i) == 1)
		philo->philo_num = ft_atolli(argv[(*i)]);
	else if ((*i) == 2)
		philo->time_die = ft_atolli(argv[(*i)]);
	else if ((*i) == 3)
		philo->time_eat = ft_atolli(argv[(*i)]);
	else if ((*i) == 4)
		philo->time_sleep = ft_atolli(argv[(*i)]);
	else if ((*i) == 5)
		philo->eat_num = ft_atolli(argv[(*i)]);
	if ((philo->philo_num > INT32_MAX || philo->philo_num < INT32_MIN)
		|| (philo->time_die > INT32_MAX || philo->time_die < INT32_MIN)
		|| (philo->time_eat > INT32_MAX || philo->time_eat < INT32_MIN)
		|| (philo->time_sleep > INT32_MAX || philo->time_sleep < INT32_MIN)
		|| (philo->eat_num > INT32_MAX || philo->eat_num < INT32_MIN))
		return (1);
	return (0);
}

int	ft_check_argv(char **argv, t_philo *philo)
{
	int		i;
	int		z;

	i = 1;
	while (argv[i])
	{
		z = 0;
		while (argv[i][z])
		{
			if (ft_isdigit(argv[i][z]))
				z++;
			else
				return (1);
		}
		if (ft_check_values(argv, &i, philo) > 0)
			return (1);
		i++;
	}
	return (0);
}