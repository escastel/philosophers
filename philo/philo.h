/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:19 by escastel          #+#    #+#             */
/*   Updated: 2024/02/22 16:40:36 by escastel         ###   ########.fr       */
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
	int					eating;
	int					meals_made;
	int					*dead_flag;
	size_t				last_meal;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		*dead;
	pthread_mutex_t		*meal;
	pthread_mutex_t		*write;
	struct s_control	*control;
}	t_philo;

/* pthread_t			thread; ^^^ */

typedef struct s_control
{
	int				dead_flag;
	int				num_philos;
	int				num_meals;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_t		*threads;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_control;

int		check(char **str);
int		initialize_strcutures(t_control *control, char **str);
int		ft_atoi(const char *str);
size_t	get_time(void);

#endif