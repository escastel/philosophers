/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:21 by escastel          #+#    #+#             */
/*   Updated: 2024/01/25 13:11:40 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_leaks(void)
{
	system("leaks -q philo");
}

static void	print_values(t_philo *philo)
{
	printf("num_of_philos: %d\n", philo->num_of_philos);
	printf("num_of_philos: %d\n", philo->time_to_die);
	printf("num_of_philos: %d\n", philo->time_to_eat);
	printf("num_of_philos: %d\n", philo->time_to_sleep);
	printf("num_of_meals: %d\n", philo->num_of_meals);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	/* atexit(ft_leaks); */
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (argc < 5 || argc > 6)
		return (printf("Error\n"), 1);
	if (check_and_save(argv + 1, philo))
		return (1);
	print_values(philo);
	return (0);
}
