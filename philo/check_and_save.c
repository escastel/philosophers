/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:16:57 by escastel          #+#    #+#             */
/*   Updated: 2024/01/25 13:05:01 by escastel         ###   ########.fr       */
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
			if (!((str[j][i] >= '0' && str[j][i] <= '9') || str[j][i] != '+'))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static int	save_data(char **str, t_philo *philo)
{
	printf("Función: save_data\n"); // Borrar
	philo->num_of_philos = ft_atoi(str[0]);
	if (philo->num_of_philos < 0)
		return (1);
	philo->time_to_die = ft_atoi(str[1]);
	if (philo->time_to_die < 0)
		return (1);
	philo->time_to_eat = ft_atoi(str[2]);
	if (philo->time_to_eat < 0)
		return (1);
	philo->time_to_sleep = ft_atoi(str[3]);
	if (philo->time_to_sleep < 0)
		return (1);
	if (str[4])
	{
		philo->num_of_meals = ft_atoi(str[4]);
		if (philo->num_of_meals < 0)
			return (1);
	}
	else
		philo->num_of_meals = -1;
	return (0);
}

int	check_and_save(char **str, t_philo *philo)
{
	printf("Función: check_and_save\n"); // Borrar
	if (check_content(str))
		return (printf("Error\n"), 1);
	if (save_data(str, philo))
		return (printf("Error\n"), 1);
	return (0);
}

