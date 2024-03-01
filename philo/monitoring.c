/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:46:17 by escastel          #+#    #+#             */
/*   Updated: 2024/03/01 11:27:59 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dead(t_control *control)
{
	int		i;
	long	time;
	t_philo	*philo;

	i = 0;
	philo = control->philos;
	while (i < control->num_philos)
	{
		time = get_time() - philo[i].last_meal;
		if (time >= philo[i].last_meal)
		{
			pthread_mutex_lock(&philo[i].control->dead);
			print_msg("died", philo);
			philo[i].dead_flag = 1;
			philo[i].control->end_flag = 1;
			pthread_mutex_unlock(&philo[i].control->dead);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_meals(t_control *control)
{
	t_philo	*philo;
	int		count;
	int		i;

	philo = control->philos;
	count = 0;
	i = 0;
	pthread_mutex_lock(&control->meal);
	while (i < control->num_philos)
	{
		if (philo[i].meals_made >= control->num_meals)
			count++;
		i++;
	}
	if (count == control->num_philos)
	{
		control->end_flag = 1;
		pthread_mutex_unlock(&control->meal);
		return (1);
	}
	pthread_mutex_unlock(&control->meal);
	return (0);
}

void	*monitoring(void *arg)
{
	t_control	*control;

	control = (t_control *)arg;
	while (!control->end_flag)
	{
		if (check_dead(control))
			break ;
		if (control->num_meals != -1)
			if (check_meals(control))
				break ;
	}
	return (arg);
}
