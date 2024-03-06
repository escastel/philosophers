/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:58:55 by escastel          #+#    #+#             */
/*   Updated: 2024/03/06 18:19:40 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	initialize_philos(t_control	*control, pthread_mutex_t *forks)
{
	int		i;

	i = 0;
	while (i < control->num_philos)
	{
		control->philos[i].id = i + 1;
		control->philos[i].meals_made = 0;
		control->philos[i].last_meal = get_time();
		control->philos[i].l_fork = &forks[i];
		if (i == (control->num_philos - 1))
			control->philos[i].r_fork = &forks[0];
		else
			control->philos[i].r_fork = &forks[i + 1];
		control->philos[i].control = control;
		i++;
	}
}

static int	initialize_mutex(t_control *control, pthread_mutex_t *forks)
{
	int	i;

	if (pthread_mutex_init(&control->dead, NULL))
		return (1);
	if (pthread_mutex_init(&control->meal, NULL))
		return (1);
	if (pthread_mutex_init(&control->write, NULL))
		return (1);
	i = 0;
	while (i < control->num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

static int	initialize_control(t_control *control, char **str)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * control->num_philos);
	if (!philo)
	{
		free(philo);
		return (1);
	}
	control->end_flag = 0;
	control->num_philos = ft_atoi(str[0]);
	control->time_to_die = ft_atoi(str[1]);
	control->time_to_eat = ft_atoi(str[2]);
	control->time_to_sleep = ft_atoi(str[3]);
	if (str[4])
		control->num_meals = ft_atoi(str[4]);
	else
		control->num_meals = -1;
	control->philos = philo;
	return (0);
}

int	initialize_structures(t_control *control, char **str,
	pthread_mutex_t *forks)
{
	if (initialize_control(control, str))
	{
		printf("Problem with allocating memory with malloc\n");
		return (1);
	}
	if (initialize_mutex(control, forks))
	{
		printf("Problem with mutex creation\n");
		ft_clean_program(control);
		return (1);
	}
	initialize_philos(control, forks);
	return (0);
}
