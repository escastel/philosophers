/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:52:54 by escastel          #+#    #+#             */
/*   Updated: 2024/03/06 18:02:57 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (str[i] - '0') + (r * 10);
		i++;
	}
	return (r * j);
}

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		printf("Error\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(char	*print, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->control->write);
	time = get_time() - philo->control->start_time;
	if (!philo->control->end_flag)
		printf("%ld %d %s\n", time, philo->id, print);
	pthread_mutex_unlock(&philo->control->write);
	return ;
}

void	ft_usleep(long time)
{
	long	end;

	end = get_time();
	while ((get_time() - end) < time)
		usleep(500);
	return ;
}

void	ft_clean_program(t_control *control)
{
	int	i;

	pthread_mutex_destroy(&control->meal);
	pthread_mutex_destroy(&control->dead);
	pthread_mutex_destroy(&control->write);
	i = 0;
	while (i < control->num_philos)
	{
		pthread_mutex_destroy(control->philos[i].r_fork);
		i++;
	}
	free(control->philos);
	free(control);
}
