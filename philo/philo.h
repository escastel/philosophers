/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:19 by escastel          #+#    #+#             */
/*   Updated: 2024/02/05 16:54:11 by escastel         ###   ########.fr       */
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
	int					fork_id;
	int					meals;
	long int			last_meal;
	struct s_monitor	*monitor;
}	t_philo;

typedef struct s_monitor
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	int				forks;
	int				meals;
	long int		time;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_monitor;

int	ft_atoi(const char *str);
int	check_and_save(char **str, t_monitor *monitor);

#endif