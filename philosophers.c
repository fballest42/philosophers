/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2021/12/20 13:45:56 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
			philo->eat_num = -1;
		if (ft_check_argv(argv, philo) > 0)
			return (ft_print_error("Invalid arguments", 2, philo));
		// else
		// 	ft_philomain(philo)
	}
	else
		return (ft_print_error("Not valid number of arguments", 1, philo));
	printf("FILOSOFOS: %d\n - TIME_DIE: %d\n - TIME_EAT: %d\n - TIME_SLEEP: %d\n - EAT_NUM: %d\n", philo->philo_num, philo->time_die, philo->time_eat, philo->time_sleep, philo->eat_num);
	return (0);
}
