/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/11 16:39:24 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	now(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(int wait)
{
	unsigned long	time;

	time = now();
	while (now() < (time + wait))
		usleep(10);
}

int		check_meals(t_data *data, int i)
{
	while (data->eat_num && i < data->philo_num
		&& data->philos[i].meals >= data->eat_num)
		i++;
	if (i == data->philo_num)
		data->full = 1;
	return (i);
}

void	be_or_notbe(t_data *data)
{
	int		i;

	while (data->full == 0)
	{
		i = 0;
		while (i < data->philo_num && data->stop == 0)
		{
			pthread_mutex_lock(&(data->eater));
			if (data->time_die <  (int)(now() - data->philos[i].last_eat))
			{
				ft_status_show("is died ❌", i + 1, &(data->philos[i]));
				data->stop = 1;
			}
			pthread_mutex_unlock(&data->eater);
			i++;
		}
		if (data->stop == 1)
			break ;
		i = 0;
		while (data->eat_num != -1 && i < data->philo_num
			&& data->philos[i].meals >= data->eat_num)
			i++;
		data->full = (i == data->philo_num);
	}
}

void	philofree(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].left_fork = NULL;
		data->philos[i].right_fork = NULL;
		pthread_mutex_destroy(&data->forks[i]);
		data->philos[i].dp = NULL;
		i++;
	}
	free(data->philos);
	data->philos = NULL;
	free(data->forks);
	data->forks = NULL;
	pthread_mutex_destroy(&data->printer);
	pthread_mutex_destroy(&data->eater);
}
