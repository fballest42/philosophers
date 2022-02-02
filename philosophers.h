/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:05 by fballest          #+#    #+#             */
/*   Updated: 2022/02/02 23:39:38 by fballest         ###   ########.fr       */
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
# include <time.h>∫
# include <sys/time.h>

typedef struct s_hilos
{
	int				num;
	int				p_num;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	t_think;
	unsigned int	eat_num;
	unsigned int	eaten_num;
	int				alive;
	int				eated;
	unsigned int	last_eat;
	unsigned int	start_time;
	pthread_t		*hilo;
	pthread_mutex_t *left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*general;
}				t_hilos;

typedef struct s_philo
{
	int				philo_num;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				eat_num;
	int				i;
	unsigned int	init_time;
	unsigned int	current_time;
	int				check;
	t_hilos			*hilos;
	pthread_mutex_t	*forks;
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
