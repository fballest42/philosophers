/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/07 12:27:57 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_routine(t_hilos *p)
{
	if (*p->alive != 1)
		ft_status_show("is sleeping", p->num, p);
	ft_usleep(p, p->t_sleep);
}

void	think_routine(t_hilos *p)
{
	if (*p->alive != 1)
		ft_status_show("is thinking", p->num, p);
	ft_usleep(p, 5);
}

void	*philo_routine(void *rut)
{
	t_hilos		*p;

	p = (t_hilos *)rut;
	while (*p->alive != 1)
	{
		if (p->num % 2)
		{
			if (*p->alive != 1 && *p->eated == 0)
				eat_routine(p);
			if (*p->alive != 1 && *p->eated == 0)
				sleep_routine(p);
			if (*p->alive != 1 && *p->eated == 0)
				think_routine(p);
		}
		else
		{
			if (*p->alive != 1 && *p->eated == 0)
				think_routine(p);
			if (*p->alive != 1 && *p->eated == 0)
				sleep_routine(p);
			if (*p->alive != 1 && *p->eated == 0)
				eat_routine(p);
		}
	}
	return (NULL);
}

void	take_fork(t_hilos *p)
{
	if (p->num % 2)
	{
		pthread_mutex_lock(p->right_fork);
		ft_status_show("is taking the right fork", p->num, p);
		pthread_mutex_lock(p->left_fork);
		ft_status_show("is taking the left fork", p->num, p);
	}
	else
	{
		pthread_mutex_lock(p->left_fork);
		ft_status_show("is taking the left fork", p->num, p);
		pthread_mutex_lock(p->right_fork);
		ft_status_show("is taking the right fork", p->num, p);	
	}
}

void	eat_routine(t_hilos *p)
{
	pthread_mutex_lock(&p->general);
	take_fork(p);
	if (*p->alive != 1)
		ft_status_show("is eating", p->num, p);
	ft_usleep(p, p->t_eat);
	p->last_eat = now();
	p->eaten_num++;
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(&p->general);
}
