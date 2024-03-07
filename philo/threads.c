/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:43:11 by escastel          #+#    #+#             */
/*   Updated: 2024/03/07 12:27:18 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_threads(int error)
{
	if (error == 1)
		printf("Thread creation error\n");
	else if (error == 2)
		printf("Mutex creation error\n");
	return (1);
}

int	threads(t_control *control)
{
	pthread_t	monitor;
	int			i;

	control->start_time = get_time();
	if (pthread_create(&monitor, NULL, &monitoring, control))
		return (error_threads(1));
	i = 0;
	while (i < control->num_philos)
	{
		if (pthread_create(&control->philos[i].thread, NULL,
				&routine, &control->philos[i]))
			return (error_threads(1));
		i++;
	}
	if (pthread_join(monitor, NULL))
		return (error_threads(2));
	i = 0;
	while (i < control->num_philos)
	{
		if (pthread_join(control->philos[i].thread, NULL))
			return (error_threads(2));
		i++;
	}
	return (0);
}
