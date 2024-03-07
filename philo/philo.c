/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:21 by escastel          #+#    #+#             */
/*   Updated: 2024/03/07 12:30:19 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	ft_leaks(void)
{
	system("leaks -q philo");
}
atexit(ft_leaks); */

static int	check_content(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9'))
			{
				printf("The arguments must be digits\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_control		*control;
	pthread_mutex_t	forks[200];

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	if (check_content(argv + 1))
		return (1);
	control = (t_control *)malloc(sizeof(t_control));
	if (!control)
	{
		printf("Problem with allocating memory with malloc\n");
		free(control);
		return (1);
	}
	if (initialize_structures(control, argv + 1, forks))
		return (1);
	if (threads(control))
		return (1);
	ft_clean_program(control);
	return (0);
}
