/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:33:17 by fballest          #+#    #+#             */
/*   Updated: 2022/02/14 10:51:16 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_print_error(char *err, int errnum)
{
	write(1, "Error : ", 8);
	write(1, err, ft_strlen(err));
	return (errnum);
}

int	init_values(t_data *data)
{
	data->forks = NULL;
	data->philos = NULL;
	if (pthread_mutex_init(&data->printer, NULL))
		return (1);
	if (pthread_mutex_init(&data->eater, NULL))
		return (1);
	return (0);
}

int	ft_check_values(char **argv, int *i, t_data *data)
{
	long	num;

	num = ft_atolli(argv[(*i)]);
	if (num > INT32_MAX || num < INT32_MIN || num <= 0)
		return (1);
	else if ((*i) == 1)
		data->philo_num = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 2)
		data->time_die = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 3)
		data->time_eat = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 4)
		data->time_sleep = (int)ft_atolli(argv[(*i)]);
	else if ((*i) == 5)
		data->eat_num = (int)ft_atolli(argv[(*i)]);
	if (init_values(data))
		return (1);
	return (0);
}

int	ft_check_argv(char **argv, t_data *data)
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
		if (ft_check_values(argv, &i, data) > 0)
			return (1);
		i++;
	}
	return (0);
}
