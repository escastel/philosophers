/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:16:57 by escastel          #+#    #+#             */
/*   Updated: 2024/02/29 12:32:57 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check(char **str)
{
	if (check_content(str))
		return (printf("Error\n"), 1);
	return (0);
}
