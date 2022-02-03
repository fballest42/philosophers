/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/03 00:43:47 by fballest         ###   ########.fr       */
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

void	be_or_notbe(t_philo *philo)
{
	int		i;
	
	while (philo->check != 1)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			if (philo->hilos[i].t_die < now())
			{
				if (philo->hilos[i].alive != 1 && philo->hilos[i].eated != 1)
					ft_status_show("is died\n", i, &philo->hilos[i]);
				philo->hilos[i].alive = 1;
				pthread_detach(*philo->hilos[i].hilo);
			}
			if (philo->eat_num != 0 && philo->hilos[i].eaten_num == (unsigned int)philo->eat_num)
				philo->hilos[i].eated = 1;
			i++;
		}
	}
}

void	waiting_for(t_philo *philo)
{
	int		i;

	i = 0;
	while(i < philo->philo_num)
		pthread_join(*philo->hilos[i++].hilo, NULL);
}
