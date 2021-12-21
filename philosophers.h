/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:32:05 by fballest          #+#    #+#             */
/*   Updated: 2021/12/21 12:56:23 by fballest         ###   ########.fr       */
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
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_num;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				eat_num;
	int				**fork;
	int				i;
	unsigned int	init_time;
	unsigned int	current_time;
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
