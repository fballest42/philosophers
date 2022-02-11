/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/11 18:53:29 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_routine(t_philos *p)
{
	if (p->dp->alive == 0 && p->dp->eaten == 0)
		ft_status_show("is sleeping 🛌", p->num, p);
	ft_usleep(p->dp->time_sleep);
}

void	think_routine(t_philos *p)
{
	if (p->dp->alive == 0 && p->dp->eaten == 0)
		ft_status_show("is thinking 💭", p->num, p);
}

void	*philo_routine(void *rut)
{
	t_philos		*p;

	p = (t_philos *)rut;
	if (p->dp->philo_num == 1)
	{
		ft_status_show("has taken the right fork 🍴", p->num, p);
		ft_usleep(p->dp->time_die);
		return (NULL);
	}
	if (p->num % 2)
		ft_usleep(2);
	while (p->dp->alive == 0 && p->dp->eaten == 0)
	{
		eat_routine(p);
		sleep_routine(p);
		think_routine(p);
	}
	return (NULL);
}

int	take_fork(t_philos *p)
{
	if (p->num == p->dp->philo_num + 1)
	{
		pthread_mutex_lock(p->left_fork);
		ft_status_show("has taken the left fork 🍴", p->num, p);
		pthread_mutex_lock(p->right_fork);
		ft_status_show("has taken the right fork 🍴", p->num, p);
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		ft_status_show("has taken the right fork 🍴", p->num, p);
		pthread_mutex_lock(p->left_fork);
		ft_status_show("has taken the left fork 🍴", p->num, p);
	}
	return (0);
}

void	eat_routine(t_philos *p)
{
	t_data		*dat;

	dat = p->dp;
	take_fork(p);
	pthread_mutex_lock(&(dat->eater));
	ft_status_show("is eating 🍝", p->num, p);
	p->last_eat = now();
	pthread_mutex_unlock(&(dat->eater));
	ft_usleep(dat->time_eat);
	p->meals++;
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}
