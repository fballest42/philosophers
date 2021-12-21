/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2021/12/21 12:59:24 by fballest         ###   ########.fr       */
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

void	*philo_routine(void *arg)
{
	t_philo		*p1;

	p1 = (t_philo *)arg;
	p1->current_time = now() - p1->init_time;
	printf("Este es el filosofo %d creado una vez pasado %u milisegundos\n", p1->i, p1->current_time);
	return ((void *)0);
}

int		philomain(t_philo *philo)
{
	pthread_t		filo[philo->philo_num];

	philo->fork = ft_calloc(sizeof(int *), philo->philo_num);
	philo->i = 0;
	philo->init_time = now();
	while (philo->i < philo->philo_num)
	{
		if (pthread_create(&filo[philo->i], NULL, philo_routine, (void *)philo) != 0)
			return (1);
		philo->fork[philo->i] = 0;
		usleep (50);
		philo->i++;
	}
	return (0);
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
	}
	else
		return (ft_print_error("Not valid number of arguments", 1, philo));
	printf("FILOSOFOS: %d\n - TIME_DIE: %d\n - TIME_EAT: %d\n - TIME_SLEEP: %d\n - EAT_NUM: %d\n", philo->philo_num, philo->time_die, philo->time_eat, philo->time_sleep, philo->eat_num);
	free(philo);
	return (0);
}
