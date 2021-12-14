/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:05 by fballest          #+#    #+#             */
/*   Updated: 2021/12/14 13:34:33 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <pthread.h>
# include <sys/stat.h>

typedef struct s_philo
{
	pthread_t	philo;
	long		philo_num;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			eat_num;
}				t_philo;

/*
** PARSER.C
*/
int			ft_print_error(char *err, int errnum, t_philo *philo);
int			ft_check_values(char **argv, int *i, t_philo *philo);
int			ft_check_argv(char **argv, t_philo *philo);

/*
** PHILOSOPHERS.C
*/
int			main(int argc, char **argv);

/*
** UTILS.C
*/
int			ft_isdigit(int c);
long int	ft_atolli(const char *str);
void		ft_bzero(void *str, size_t n);
void		*ft_calloc(size_t count, size_t size);
#endif
