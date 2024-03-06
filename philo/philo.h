/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:19 by escastel          #+#    #+#             */
/*   Updated: 2024/03/06 17:09:11 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>   // printf
# include <stdlib.h>  // malloc, free
# include <string.h>  // memset
# include <unistd.h>  // write, usleep
# include <pthread.h> // threads and mutex
# include <sys/time.h> // gettimeofday

typedef struct s_philo
{
	int					id;
	int					meals_made;
	long				last_meal;
	pthread_t			thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	struct s_control	*control;
}	t_philo;

typedef struct s_control
{
	int				end_flag;
	int				num_philos;
	int				num_meals;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_control;

int		check(char **str);
int		initialize_structures(t_control *control, char **str,
			pthread_mutex_t *forks);
int		threads(t_control *control);
void	*routine(void *arg);
void	*monitoring(void *arg);
void	print_msg(char	*print, t_philo *philo);
int		ft_atoi(const char *str);
long	get_time(void);
void	ft_usleep(long time);

#endif