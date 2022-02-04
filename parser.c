/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:33:17 by fballest          #+#    #+#             */
/*   Updated: 2022/02/04 11:14:49 by fballest         ###   ########.fr       */
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
	long	num;

	num = ft_atolli(argv[(*i)]);
	if (num > INT32_MAX || num < INT32_MIN || num < 0)
		return (1);
	else if ((*i) == 1)
		philo->philo_num = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 2)
		philo->time_die = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 3)
		philo->time_eat = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 4)
		philo->time_sleep = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 5)
		philo->eat_num = (int)ft_atolli(argv[(*i)]);
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
		if (argv[i][0] == '-' || argv[i][0] == '+')
			z++;
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
	if (philo->philo_num <= 0 || philo->time_die <= 0
		|| philo->time_eat <= 0 || philo->time_sleep <= 0 || (philo->eat_num < 0 && i == 5))
	  	return (1);
	return (0);
}
