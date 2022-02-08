/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/08 11:32:36 by fballest         ###   ########.fr       */
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
	if (time == 1)
		time = time / 1000;
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
	while (x < philo->philo_num)
	{
		pthread_detach(philo->hilos[x].hilo);
		pthread_mutex_destroy(&philo->forks[x]);
		pthread_mutex_destroy(&philo->hilos[i].general);
		x++;
	}
}

int		check_eated(t_philo *philo)
{
	int 	i;

	i = 0;
	while (i < philo->philo_num)
	{
		if (philo->hilos[i].eated == 0)
			return (0);
		i++;
	}
	return (1);
}

void	be_or_notbe(t_philo *philo)
{
	int		i;
	while (philo->alives == 0)
	{
		i = 0;
		while (i < philo->philo_num && philo->alives == 0 && philo->hilos[i].eated == 0)
		{
			if (philo->hilos[i].t_die <  (now() - philo->hilos[i].last_eat))
			{
				if (*philo->hilos[i].alive == 0)
					ft_status_show("is died", i + 1, &philo->hilos[i]);
				*philo->hilos[i].alive = 1;
				waiting_for(philo);
			}
			if (philo->hilos[i].eated == 1)
				break ;
			i++;
		}
		if (check_eated(philo))
			break ;
	}

}

void	waiting_for(t_philo *philo)
{
	int		i;

	i = 0;

	pthread_mutex_destroy(&philo->printer);
	while(i < philo->philo_num)
		pthread_join(philo->hilos[i++].hilo, NULL);
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		pthread_mutex_destroy(&philo->hilos[i].general);
		pthread_detach(philo->hilos[i++].hilo);
	}
	
}
