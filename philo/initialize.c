/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:58:55 by escastel          #+#    #+#             */
/*   Updated: 2024/02/05 17:11:45 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_mutex(t_monitor *monitor)
{
	int	i;

	i = 1;
	while (i <= forks)
	{
		if (pthread_mutex_init(&monitor->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	initialize_threads(t_monitor *monitor)
{
	int	i;

	i = 1;
	while (i <= monitor->num_of_philos)
	{
		if (pthreadd_create(&monitor->philo[i], NULL, routine, NULL))
			return (1);
	}
	return (0);
}