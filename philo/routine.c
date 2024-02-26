/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:45:36 by escastel          #+#    #+#             */
/*   Updated: 2024/02/26 16:29:28 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	print_msg("is thinking", philo);
}

static void	sleep(t_philo *philo)
{
	print_msg("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

static void	eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->r_fork))
		return ;
	print_msg("has taken a fork", philo);
	if (philo->num_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		print_msg("died", philo);
		pthread_mutex_unlock(&philo->r_fork)
		return ;
	}
	if (pthread_mutex_lock(&philo->l_fork))
		return ;
	print_msg("has taken a fork", philo);
	print_msg("is eating", philo);
	if (pthread_mutex_lock(philo->meal))
		return ;
	philo->last_meal = get_time();
	philo->meals_made++;
	if (pthread_mutex_unlock(philo->meal))
		return ;
	ft_usleep(philo->time_to_eat);
	if (pthread_mutex_unlock(&philo->r_fork))
		return ;
	if (pthread_mutex_unlock(&philo->l_fork))
		return ;
}

void	routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		ft_usleep(1);
	while (!philo->dead_flag)
	{
		eat(philo);
		sleep(philo);
		think(philo);
	}
	return (arg);
}
