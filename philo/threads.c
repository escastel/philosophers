/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:43:11 by escastel          #+#    #+#             */
/*   Updated: 2024/03/06 16:55:20 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Hacer limpieza en cada return (1); >>
*/

int	threads(t_control *control)
{
	pthread_t	monitor;
	int			i;

	control->start_time = get_time();
	if (pthread_create(&monitor, NULL, &monitoring, control))
		return (1);
	i = 0;
	while (i < control->num_philos)
	{
		if (pthread_create(&control->philos[i].thread, NULL,
				&routine, &control->philos[i]))
			return (1);
		i++;
	}
	if (pthread_join(monitor, NULL))
		return (1);
	i = 0;
	while (i < control->num_philos)
	{
		if (pthread_join(control->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
