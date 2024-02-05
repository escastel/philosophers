/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:16:57 by escastel          #+#    #+#             */
/*   Updated: 2024/02/05 15:17:30 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_content(char **str)
{
	int	i;
	int	j;

	j = 0;
	printf("Función: check_content\n"); // Borrar
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9'))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static int	save_args(char **str, t_monitor *monitor)
{
	printf("Función: save_data\n"); // Borrar
	monitor->num_of_philos = ft_atoi(str[0]);
	if (monitor->num_of_philos < 0)
		return (1);
	monitor->forks = ft_atoi(str[0]);
	monitor->time_to_die = ft_atoi(str[1]);
	if (monitor->time_to_die < 0)
		return (1);
	monitor->time_to_eat = ft_atoi(str[2]);
	if (monitor->time_to_eat < 0)
		return (1);
	monitor->time_to_sleep = ft_atoi(str[3]);
	if (monitor->time_to_sleep < 0)
		return (1);
	if (str[4])
	{
		monitor->num_of_meals = ft_atoi(str[4]);
		if (monitor->num_of_meals < 0)
			return (1);
	}
	else
		monitor->num_of_meals = -1;
	return (0);
}

static void	initialize(t_monitor *monitor)
{
	t_philo	*philo;
	int		i;

	printf("Función: initialize\n"); // Borrar
	monitor->philo = (t_philo *)malloc(sizeof(t_philo));
	philo = monitor->philo;
	i = 1;
	while (i <= monitor->num_of_philos)
	{
		philo->id = i;
		philo->fork_id = i;
		philo->meals = 0;
		philo->time_last_meal = 0;
		monitor->meals = 0;
		monitor->time = 0;
		i++;
	}
}

int	check_and_save(char **str, t_monitor *monitor)
{
	printf("Función: check_and_save\n"); // Borrar
	if (check_content(str))
		return (printf("Error\n"), 1);
	if (save_args(str, monitor))
		return (printf("Error\n"), 1);
	initialize(monitor);
	return (0);
}
