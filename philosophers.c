/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/03 00:56:13 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	setphilovalues(t_philo *philo, int	i)
{
	philo->check = 0;
	philo->hilos[i].alive = 1;
	philo->hilos[i].eated = 1;
	philo->hilos[i].num = i + 1;
	philo->hilos[i].p_num = philo->philo_num;
	philo->hilos[i].t_die = philo->time_die;
	philo->hilos[i].t_eat = philo->time_eat;
	philo->hilos[i].t_sleep = philo->time_sleep;
	philo->hilos[i].t_think = 50;
	philo->hilos[i].eat_num = philo->eat_num;
	philo->hilos[i].eaten_num = 0;
	philo->hilos[i].start_time = philo->init_time;
	philo->hilos[i].left_fork = &philo->forks[i];
	if (i == philo->philo_num - 1)
		philo->hilos[i].right_fork = &philo->forks[0];
	else
		philo->hilos[i].right_fork = &philo->forks[i + 1];
}

int		philomain(t_philo *philo)
{
	philo->i = 0;
	philo->init_time = now();
	philo->hilos = malloc(sizeof(t_hilos) * philo->philo_num);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_num);
	
	while (philo->i < philo->philo_num)
	{
		setphilovalues(philo, philo->i);
		// pthread_mutex_init(philo->hilos[philo->i].general, NULL);
		// pthread_mutex_init(&philo->forks, NULL);
		if (pthread_create(philo->hilos[philo->i].hilo, NULL,
					philo_routine, &philo->hilos[philo->i]) != 0)
			return (1);
		philo->hilos[philo->i].last_eat = now();
		usleep (50);
		philo->i++;
	}
	return (0);
}

void	philofree(t_philo *philo)
{
	free(philo->hilos);
	free(philo->forks);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
			philo->eat_num = -1;
		if (ft_check_argv(argv, philo) != 0)
			return (ft_print_error("Invalid arguments", 2, philo));
		if (philomain(philo) != 0)
			return (ft_print_error("Can't create phillosphers", 3, philo));
		be_or_notbe(philo);
		waiting_for(philo);
	}
	else
		return (ft_print_error("Not valid number of arguments", 1, philo));
	philofree(philo);
	return (0);
}
