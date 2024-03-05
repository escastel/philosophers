/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:45:36 by escastel          #+#    #+#             */
/*   Updated: 2024/03/05 18:38:00 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	if (!philo->control->end_flag)
		print_msg("is thinking", philo);
}

static void	dream(t_philo *philo)
{
	if (!philo->control->end_flag)
		print_msg("is sleeping", philo);
	ft_usleep(philo->control->time_to_sleep);
}

static void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	if (!philo->control->end_flag)
		print_msg("has taken a fork", philo);
	ft_usleep(philo->control->time_to_die);
	pthread_mutex_unlock(&philo->r_fork);
	return ;
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->control->meal);
	if (!philo->control->end_flag)
	{
		print_msg("has taken a fork", philo);
		print_msg("has taken a fork", philo);
		print_msg("is eating", philo);
	}
	philo->last_meal = get_time();
	philo->meals_made++;
	ft_usleep(philo->control->time_to_eat);
	pthread_mutex_unlock(&philo->control->meal);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time();
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!philo->control->end_flag)
	{
		if (philo->control->num_philos == 1)
		{
			one_philo(philo);
			break ;
		}
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (arg);
}
