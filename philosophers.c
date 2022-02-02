/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/03 00:08:03 by fballest         ###   ########.fr       */
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
					print_status("is died\n", i, philo);
				philo->hilos[i].alive = 1;
				pthread_detach(philo->hilos[i].hilo);
			}
			if (philo->eat_num != 0 && philo->hilos[i].eaten_num == philo->eat_num)
				philo->hilos[i].eated = 1;
			i++;
		}
	}
}

void	*philo_routine(void *rut)
{
	t_hilos		*hilos;

	hilos = (t_philo *)rut;
	while (hilos->alive != 1 && hilos->eated != 1)
	{
		eat_rutine(hilos);
		if (hilos->eated != 1);
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
			print_status("is taking the right fork\n", hilos->num, hilos);
		pthread_mutex_lock(hilos->left_fork);
		if (hilos->alive != 1)
			print_status("is taking the left fork\n", hilos->num, hilos);
	}
	else
	{
		pthread_mutex_lock(hilos->left_fork);
		if (hilos->alive != 1)
			print_status("is taking the left fork\n", hilos->num, hilos);
		pthread_mutex_lock(hilos->right_fork);
		if (hilos->alive != 1)
			print_status("is taking the right fork\n", hilos->num, hilos);	
	}
}

void	eat_routine(t_hilos *hilos)
{
	pthread_mutex_lock(&hilos->general);
	take_fork(hilos);
	if (hilos->alive != 1)
		print_status("is eating\n", hilos->num, hilos);
	usleep(hilos->t_eat * 1000);
	hilos->last_eat = now();
	hilos->eaten_num++;
	pthread_mutex_unlock(hilos->left_fork);
	pthread_mutex_unlock(hilos->right_fork);
	pthread_mutex_unlock(&hilos->general);
}

void	sleep_routine(t_hilos *hilos)
{
	if (hilos->alive != 1)
		print_status("is sleeping\n", hilos->num, hilos);
	usleep(hilos->t_sleep * 1000);
}

void	think_routine(t_hilos *hilos)
{
	if (hilos->alive != 1)
		print_status("is thinking\n", hilos->num, hilos);
	usleep(hilos->t_think);
}

void	setphilovalues(t_philo *philo, int	i)
{
	philo->check = 0;
	philo->hilos[i].alive = 1;
	philo->hilos[i].eated == 1;
	philo->hilos[i].num = i + 1;
	philo->hilos[i].p_num = &philo->philo_num;
	philo->hilos[i].t_die = &philo->time_die;
	philo->hilos[i].t_eat = &philo->time_eat;
	philo->hilos[i].t_sleep = &philo->time_sleep;
	philo->hilos[i].t_think = 50;
	philo->hilos[i].eat_num = &philo->eat_num;
	philo->hilos[i].eaten_num = 0;
	philo->hilos[i].start_time = &philo->init_time;
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
		pthread_mutex_init(&philo->hilos[philo->i].general, NULL);
		pthread_mutex_init(&philo->forks[philo->i], NULL);
		if (pthread_create(&philo->hilos[philo->i].hilo, NULL,
					philo_routine, &philo->hilos[philo->i]) != 0)
			return (1);
		philo->hilos[philo->i].last_eat = now();
		setphilovalues(philo, philo->i);
		usleep (50);
		philo->i++;
	}
	return (0);
}

void	waiting_for(t_philo *philo)
{
	int		i;

	i = 0;
	while(i < philo->philo_num)
		pthread_join(philo->hilos[i++].hilo, NULL);
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
