/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:14 by fballest          #+#    #+#             */
/*   Updated: 2022/02/04 00:41:58 by fballest         ###   ########.fr       */
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

void	all_died(t_philo *philo, int i)
{
	int		x;

	x = 0;
	pthread_detach(philo->hilos[i].hilo);
	while (x < philo->philo_num)
	{
		if (x == i)
			x++;
		else
			pthread_detach(philo->hilos[x].hilo);
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
			if (philo->hilos[i].t_die < (now() - philo->hilos[i].last_eat))
			{
				if (philo->hilos[i].alive != 1 && philo->hilos[i].eated != 1)
					ft_status_show("is died", i + 1, &philo->hilos[i]);
				philo->hilos[i].alive = 1;
				philo->alives = 1;
				// printf("MUERTE EN %d\n", philo->hilos[i].t_die);
				// printf("ULTIMA COMIDA %d\n", philo->hilos[i].last_eat);
				all_died(philo, i);
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
		pthread_join(philo->hilos[i++].hilo, NULL);
}
