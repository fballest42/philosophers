/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/03 00:48:22 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_routine(t_hilos *hilos)
{
	if (hilos->alive != 1)
		ft_status_show("is sleeping\n", hilos->num, hilos);
	usleep(hilos->t_sleep * 1000);
}

void	think_routine(t_hilos *hilos)
{
	if (hilos->alive != 1)
		ft_status_show("is thinking\n", hilos->num, hilos);
	usleep(hilos->t_think);
}

void	*philo_routine(void *rut)
{
	t_hilos		*hilos;

	hilos = (t_hilos *)rut;
	while (hilos->alive != 1 && hilos->eated != 1)
	{
		eat_routine(hilos);
		if (hilos->eated != 1)
			sleep_routine(hilos);
		if (hilos->eated != 1)
			think_routine(hilos);
	}
	return (NULL);
}

void	take_fork(t_hilos *hilos)
{
	if (hilos->num % 2)
	{
		pthread_mutex_lock(hilos->right_fork);
		if (hilos->alive != 1)
			ft_status_show("is taking the right fork\n", hilos->num, hilos);
		pthread_mutex_lock(hilos->left_fork);
		if (hilos->alive != 1)
			ft_status_show("is taking the left fork\n", hilos->num, hilos);
	}
	else
	{
		pthread_mutex_lock(hilos->left_fork);
		if (hilos->alive != 1)
			ft_status_show("is taking the left fork\n", hilos->num, hilos);
		pthread_mutex_lock(hilos->right_fork);
		if (hilos->alive != 1)
			ft_status_show("is taking the right fork\n", hilos->num, hilos);	
	}
}

void	eat_routine(t_hilos *hilos)
{
	pthread_mutex_lock(hilos->general);
	take_fork(hilos);
	if (hilos->alive != 1)
		ft_status_show("is eating\n", hilos->num, hilos);
	usleep(hilos->t_eat * 1000);
	hilos->last_eat = now();
	hilos->eaten_num++;
	pthread_mutex_unlock(hilos->left_fork);
	pthread_mutex_unlock(hilos->right_fork);
	pthread_mutex_unlock(hilos->general);
}
