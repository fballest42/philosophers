/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:31:05 by fballest          #+#    #+#             */
/*   Updated: 2021/12/14 13:33:59 by fballest         ###   ########.fr       */
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
	return (0);
}
