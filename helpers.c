/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/04 12:29:55 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	now(void)
{
	struct timeval	current_time;
	unsigned int	time;

	gettimeofday(&current_time, NULL);
	time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (time);
}

void	ft_usleep(t_hilos *hilo, unsigned int time)
{
	unsigned int	init_time;
	unsigned int	fin_time;

	init_time = now();
	fin_time = init_time + time;
	while (time < fin_time)
	{
		time = now();
		usleep(hilo->p_num);
	}
}

void	all_died(t_philo *philo, int i)
{
	int		x;

	x = 0;
	pthread_detach(philo->hilos[i].hilo);
	if (i == philo->philo_num - 1)
		pthread_mutex_destroy(&philo->forks[0]);
	else
		pthread_mutex_destroy(&philo->forks[i]);
	while (x < philo->philo_num)
	{
		if (x == i)
			x++;
		else
		{
			pthread_detach(philo->hilos[x].hilo);
			if ((i != (philo->philo_num - 1) && x != 0) || x != i)
				pthread_mutex_destroy(&philo->forks[x]);
		}
		pthread_mutex_destroy(&philo->hilos[x].general);
		x++;
	}
}

void	be_or_notbe(t_philo *philo)
{
	int		i;
	
	while (philo->alives != 1)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			if (philo->hilos[i].t_die <  (now() - philo->hilos[i].last_eat))
			{
				if (philo->hilos[i].alive != 1 && philo->hilos[i].eated != 1)
					ft_status_show("is died", i + 1, &philo->hilos[i]);
				philo->hilos[i].alive = 1;
				philo->alives = 1;
				all_died(philo, i);
			}
			if (philo->hilos[i].eat_num != 0 && philo->hilos[i].eaten_num == philo->eat_num)
			{
				philo->hilos[i].eated = 1;
				philo->hilos[i].alive = 1;
			}
			i++;
		}
	}
}

void	waiting_for(t_philo *philo)
{
	int		i;

	i = 0;
	while(i < philo->philo_num)
	{
		pthread_detach(philo->hilos[i].hilo);
		pthread_mutex_destroy(&philo->forks[i]);
	}
}
