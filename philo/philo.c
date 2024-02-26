/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:21 by escastel          #+#    #+#             */
/*   Updated: 2024/02/26 10:40:43 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	ft_leaks(void)
{
	system("leaks -q philo");
}
atexit(ft_leaks);

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
	t_control	*control;

	control = (t_control *)malloc(sizeof(t_control));
	if (argc < 5 || argc > 6)
		return (printf("Error\n"), 1);
	if (check(argv + 1))
		return (1);
	if (initialize_structures(control, argv + 1))
		return (1);
	return (0);
}
