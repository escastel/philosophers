/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:58:55 by escastel          #+#    #+#             */
/*   Updated: 2024/02/08 14:38:34 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_mutex(t_monitor *monitor)
{
	int	i;

	i = 1;
	while (i <= monitor->forks)
	{
		if (pthread_mutex_init(&monitor->forks_mutex[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	initialize_threads(t_monitor *monitor)
{
	pthread_t	ctrl;
	int			i;

	i = 1;
	while (i <= monitor->num_of_philos)
	{
		if (pthreadd_create(&monitor->philo[i], NULL, routine, NULL))
			return (1);
	}
	return (0);
}
