/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/04 12:25:27 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_routine(t_hilos *hilo)
{
	if (hilo->alive != 1)
		ft_status_show("is sleeping", hilo->num, hilo);
	ft_usleep(hilo, (useconds_t)hilo->t_sleep);
}

void	think_routine(t_hilos *hilo)
{
	if (hilo->alive != 1)
		ft_status_show("is thinking", hilo->num, hilo);
	ft_usleep(hilo, 50);
}

void	*philo_routine(void *rut)
{
	t_hilos		*hilo;

	hilo = (t_hilos *)rut;
	while (hilo->alive != 1 && hilo->eated != 1)
	{
		if (hilo->eated != 1 && hilo->alive != 1)
		{
			eat_routine(hilo);
			ft_usleep(hilo, hilo->t_eat);
			hilo->last_eat = now();
		}
		if (hilo->eated != 1 && hilo->alive != 1)
			sleep_routine(hilo);
		if (hilo->eated != 1 && hilo->alive != 1)
			think_routine(hilo);
	}
	return (NULL);
}

void	take_fork(t_hilos *hilo)
{
	if (hilo->num % 2)
	{
		pthread_mutex_lock(hilo->right_fork);
		if (hilo->alive != 1)
			ft_status_show("is taking the right fork", hilo->num, hilo);
		pthread_mutex_lock(hilo->left_fork);
		if (hilo->alive != 1)
			ft_status_show("is taking the left fork", hilo->num, hilo);
	}
	else
	{
		pthread_mutex_lock(hilo->left_fork);
		if (hilo->alive != 1 && hilo->eated != 1)
			ft_status_show("is taking the left fork", hilo->num, hilo);
		pthread_mutex_lock(hilo->right_fork);
		if (hilo->alive != 1 && hilo->eated != 1)
			ft_status_show("is taking the right fork", hilo->num, hilo);	
	}
}

void	eat_routine(t_hilos *hilo)
{
	useconds_t	 i;

	pthread_mutex_lock(&hilo->general);
	take_fork(hilo);
	if (hilo->alive != 1)
		ft_status_show("is eating", hilo->num, hilo);
	i = hilo->t_eat;
	hilo->last_eat = now();
	hilo->eaten_num++;
	if (hilo->eaten_num == hilo->eat_num)
		hilo->eated = 1;
	if (hilo->num % 2)
	{
		pthread_mutex_unlock(hilo->right_fork);
		pthread_mutex_unlock(hilo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(hilo->left_fork);
		pthread_mutex_unlock(hilo->right_fork);

	}
	pthread_mutex_unlock(&hilo->general);
}
