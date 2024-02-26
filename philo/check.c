/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:16:57 by escastel          #+#    #+#             */
/*   Updated: 2024/02/26 10:36:57 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_content(char **str)
{
	int	i;
	int	j;

	printf("Función: check_content\n"); // Borrar
	j = 0;
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

static int	check_int(char **str)
{
	printf("Función: check_int\n"); // Borrar
	if (ft_atoi(str[0]) < 0)
		return (1);
	if (ft_atoi(str[1]) < 0)
		return (1);
	if (ft_atoi(str[2]) < 0)
		return (1);
	if (ft_atoi(str[3]) < 0)
		return (1);
	if (str[4])
	{
		if (ft_atoi(str[4]) < 0)
			return (1);
	}
	return (0);
}

int	check(char **str)
{
	printf("Función: check_and_save\n"); // Borrar
	if (check_content(str))
		return (printf("Error\n"), 1);
	if (check_int(str))
		return (printf("Error\n"), 1);
	return (0);
}
