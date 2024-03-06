/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:21 by escastel          #+#    #+#             */
/*   Updated: 2024/03/06 17:04:37 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	ft_leaks(void)
{
	system("leaks -q philo");
}
atexit(ft_leaks);
*/

int	main(int argc, char **argv)
{
	t_control		*control;
	pthread_mutex_t	forks[200];

	control = (t_control *)malloc(sizeof(t_control));
	if (argc < 5 || argc > 6)
		return (printf("Error\n"), 1);
	if (check(argv + 1))
		return (1);
	if (initialize_structures(control, argv + 1, forks))
		return (1);
	threads(control);
	return (0);
}
