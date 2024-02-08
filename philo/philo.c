/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:21 by escastel          #+#    #+#             */
/*   Updated: 2024/02/08 12:39:22 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	ft_leaks(void)
{
	system("leaks -q philo");
}

static void	print_values(t_monitor *monitor)
{
	printf("num_of_philos: %d\n", monitor->num_of_philos);
	printf("time_to_die: %d ms\n", monitor->time_to_die);
	printf("time_to_eat: %d ms\n", monitor->time_to_eat);
	printf("time_to_sleep: %d ms\n", monitor->time_to_sleep);
	printf("num_of_meals: %d\n", monitor->num_of_meals);
} */

int	main(int argc, char **argv)
{
	t_monitor	*monitor;

	/* atexit(ft_leaks); */
	monitor = (t_monitor *)malloc(sizeof(t_monitor));
	if (argc < 5 || argc > 6)
		return (printf("Error\n"), 1);
	if (check_and_save(argv + 1, monitor))
		return (1);
	return (0);
}
