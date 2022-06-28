/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:05 by fballest          #+#    #+#             */
/*   Updated: 2022/03/02 14:40:17 by fballest         ###   ########.fr       */
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
# include <time.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				num;
	int				meals;
	unsigned long	last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*dp;
}				t_philos;

typedef struct s_data
{
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_num;
	int				eaten;
	unsigned long	init_time;
	unsigned long	current_time;
	int				alive;
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printer;
	pthread_mutex_t	eater;
}				t_data;

/*
** PARSER.C
*/
int				ft_print_error(char *err, int errnum);
int				init_values(t_data *data);
int				ft_check_values(char **argv, int *i, t_data *data);
int				ft_check_argv(char **argv, t_data *data);

/*
** PHILOSOPHERS.C
*/
int				setphilovalues(t_data *data);
int				init_forks(t_data *data);
int				joining_philos(t_data *data);
int				philomain(t_data *data);
int				main(int argc, char **argv);

/*
** HELPERS.C
*/
unsigned long	now(void);
void			ft_usleep(int wait);
void			dead_routine(t_data *data);
void			be_or_notbe(t_data *data);
void			philofree(t_data *data);

/*
** ROUTINE.C
*/
void			sleep_routine(t_philos *p);
void			think_routine(t_philos *p);
void			*philo_routine(void *rut);
int				take_fork(t_philos *p);
void			eat_routine(t_philos *p);

/*
** UTILS.C
*/
int				ft_strlen(char *str);
void			ft_status_show(char *str, int i, t_philos *p, int force);
int				ft_isdigit(int c);
long int		ft_atolli(const char *str);

#endif
