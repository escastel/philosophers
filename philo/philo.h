/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:19 by escastel          #+#    #+#             */
/*   Updated: 2024/01/25 12:54:19 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>   // printf
# include <stdlib.h>  // malloc, free
# include <string.h>  // memset
# include <unistd.h>  // write, usleep
# include <pthread.h> // hilos y mutex
# include <sys/time.h> // gettimeofday

typedef struct s_philo
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
}	t_philo;

int	ft_atoi(const char *str);
int	check_and_save(char **str, t_philo *philo);

#endif