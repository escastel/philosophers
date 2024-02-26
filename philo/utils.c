/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:52:54 by escastel          #+#    #+#             */
/*   Updated: 2024/02/26 16:30:03 by escastel         ###   ########.fr       */
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

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		printf("Error\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(char	*print, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write);
	time = get_time();
	printf("%zu %d %s\n", time, philo->id, print);
	pthread_mutex_unlock(philo->write);
	return ;
}

void	ft_usleep(size_t time)
{
	size_t	end;

	end = get_time();
	while ((get_time() - end) < time)
		usleep(500);
	return ;
}
