/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/08 12:11:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	setphilovalues(t_philo *philo, int	i)
{
	philo->hilos[i].last_eat = now();
	pthread_mutex_init(&philo->hilos[philo->i].general, NULL);
	philo->hilos[i].alive = &philo->alives;
	philo->hilos[i].eated = 0;
	philo->hilos[i].start_time = philo->init_time;
	philo->hilos[i].num = i + 1;
	philo->hilos[i].t_die = philo->time_die;
	philo->hilos[i].t_eat = philo->time_eat;
	philo->hilos[i].t_sleep = philo->time_sleep;
	philo->hilos[i].eat_num = philo->eat_num;
	philo->hilos[i].eaten_num = 0;
	philo->hilos[i].printing = &philo->printer;
	if (i == 0)
	{
		philo->hilos[i].left_fork = &philo->forks[philo->philo_num - 1];
		philo->hilos[i].right_fork = &philo->forks[i];
	}
	else
	{
		philo->hilos[i].left_fork = &philo->forks[i - 1];
		philo->hilos[i].right_fork = &philo->forks[i];
	}
}

int		philomain(t_philo *philo)
{
	philo->i = 0;
	philo->hilos = malloc(sizeof(t_hilos) * philo->philo_num);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_num);
	pthread_mutex_init(&philo->printer, NULL);
	philo->init_time = now();
	while (philo->i < philo->philo_num)
		pthread_mutex_init(&philo->forks[philo->i++], NULL);
	philo->i = 0;
	while (philo->i <= philo->philo_num)
	{
		setphilovalues(philo, philo->i);
		if (pthread_create(&philo->hilos[philo->i].hilo, NULL,
				philo_routine, &philo->hilos[philo->i]) != 0)
			return (1);
		ft_usleep(&philo->hilos[philo->i], 5);
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
