/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/04 00:33:58 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_routine(t_hilos *hilo)
{
	if (hilo->alive != 1)
		ft_status_show("is sleeping", hilo->num, hilo);
	usleep(hilo->t_sleep * 1000);
}

void	think_routine(t_hilos *hilo)
{
	if (hilo->alive != 1)
		ft_status_show("is thinking", hilo->num, hilo);
	usleep(50);
}

void	*philo_routine(void *rut)
{
	t_hilos		*hilo;

	hilo = (t_hilos *)rut;
	while (hilo->alive != 1 && hilo->eated != 1)
	{
		eat_routine(hilo);
		if (hilo->eated != 1)
			sleep_routine(hilo);
		if (hilo->eated != 1)
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
	pthread_mutex_lock(&hilo->general);
	take_fork(hilo);
	if (hilo->alive != 1)
		ft_status_show("is eating", hilo->num, hilo);
	usleep(hilo->t_eat * 1000);
	hilo->last_eat = now();
	printf("COMIDA %d", hilo->last_eat);
	hilo->eaten_num++;
	pthread_mutex_unlock(hilo->right_fork);
	pthread_mutex_unlock(hilo->left_fork);
	pthread_mutex_unlock(&hilo->general);
}
