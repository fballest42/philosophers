/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/03/03 14:56:39 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	setphilovalues(t_data *data)
{
	int			i;

	i = 0;
	data->philos = (t_philos *)malloc(sizeof(t_philos) * data->philo_num);
	if (!data->philos)
		return (1);
	while (i < data->philo_num)
	{
		data->philos[i].num = i + 1;
		data->philos[i].dp = data;
		data->philos[i].last_eat = now();
		data->philos[i].meals = 0;
		data->philos[i].right_fork = &(data->forks[i]);
		if (i == 0)
			data->philos[i].left_fork = &(data->forks[data->philo_num - 1]);
		else
			data->philos[i].left_fork = &(data->forks[i - 1]);
		i++;
	}
	data->alive = 0;
	data->eaten = 0;
	data->init_time = now();
	return (0);
}

int	init_forks(t_data *data)
{
	int		i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->philo_num);
	if (!data->forks)
		return (1);
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	joining_philos(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	philomain(t_data *data)
{
	int		i;

	i = 0;
	if (init_forks(data))
		return (1);
	if (setphilovalues(data))
		return (1);
	while (i < data->philo_num)
	{
		if (pthread_create(&(data->philos[i].thread), NULL,
				philo_routine, &(data->philos[i])))
			return (1);
		i++;
	}
	be_or_notbe(data);
	if (joining_philos(data))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_data		data;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
			data.eat_num = -1;
		if (ft_check_argv(argv, &data) != 0)
			i = (ft_print_error("Invalid arguments\n", 2));
		if (i == 0 && philomain(&data) != 0)
			i = (ft_print_error("Can't create phillosphers\n", 3));
	}
	else
		i = (ft_print_error("Not valid number of arguments\n", 1));
	if (i == 0)
		philofree(&data);
	return (i);
}
