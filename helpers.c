/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/15 10:23:11 by fballest         ###   ########.fr       */
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
		usleep(500);
}

void	be_or_notbe(t_data *data)
{
	int		i;

	while (data->eaten == 0)
	{
		i = 0;
		while (i < data->philo_num && data->alive == 0)
		{
			pthread_mutex_lock(&(data->eater));
			if (data->time_die < (int)(now() - data->philos[i].last_eat))
			{
				data->alive = 1;
				ft_status_show("is died", i + 1, &(data->philos[i]), 1);
			}
			pthread_mutex_unlock(&(data->eater));
			i++;
		}
		if (data->alive == 1)
			break ;
		i = 0;
		while (data->eat_num != -1 && i < data->philo_num
			&& data->philos[i].meals >= data->eat_num)
			i++;
		data->eaten = (i == data->philo_num);
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
		if (data->forks)
			pthread_mutex_destroy(&(data->forks[i]));
		data->philos[i].dp = NULL;
		i++;
	}
	pthread_mutex_destroy(&(data->printer));
	pthread_mutex_destroy(&(data->eater));
	if (data->philos)
		free(data->philos);
	data->philos = NULL;
	if (data->forks)
		free(data->forks);
	data->forks = NULL;
}
