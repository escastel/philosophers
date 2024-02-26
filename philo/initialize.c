/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:58:55 by escastel          #+#    #+#             */
/*   Updated: 2024/02/26 16:26:47 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	initialize_philos(t_control	*control, t_philo *philo)
{
	int		i;

	i = 0;
	while (i <= control->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals_made = 0;
		philo[i].num_philos = &control->num_philos;
		philo[i].dead_flag = &control->dead_flag;
		philo[i].last_meal = get_time();
		philo[i].time_to_die = &control->time_to_die;
		philo[i].time_to_eat = &control->time_to_eat;
		philo[i].time_to_sleep = &control->time_to_sleep;
		philo[i].dead = &control->dead;
		philo[i].meal = &control->meal;
		philo[i].write = &control->write;
		philo[i].r_fork = control->forks[i];
		if (i == (control->num_philos - 1))
			philo[i].l_fork = control->forks[0];
		else
			philo[i].l_fork = control->forks[i + 1];
		philo[i].control = control;
		i++;
	}
}

static int	initialize_mutex(t_control *control)
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
		pthread_mutex_init(&control->forks[i], NULL);
		i++;
	}
	return (0);
}

static int	initialize_control(t_control *control, char **str)
{
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo));
	if (!philos)
		return (1);
	control->forks = (pthread_t *)malloc(sizeof(pthread_t));
	if (!control->forks)
		return (1);
	control->dead_flag = 0;
	control->num_philos = ft_atoi(str[0]);
	control->time_to_die = ft_atoi(str[1]);
	control->time_to_eat = ft_atoi(str[2]);
	control->time_to_sleep = ft_atoi(str[3]);
	if (str[4])
		control->num_meals = ft_atoi(str[4]);
	else
		control->num_meals = -1;
	control->philos = philos;
	return (0);
}

int	initialize_structures(t_control *control, char **str)
{
	initialize_philos(control, control->philos);
	if (initialize_control(control, str))
		return (1);
	if (initialize_mutex(control))
		return (1);
	return (0);
}
