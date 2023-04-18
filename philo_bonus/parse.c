/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:23:21 by ykarabul          #+#    #+#             */
/*   Updated: 2023/04/17 11:23:49 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_digits(char *av[])
{
	int	layer;
	int	index;

	layer = 1;
	while (av[layer])
	{
		index = 0;
		while (av[layer][index])
		{
			if (!ft_isdigit(av[layer][index]))
				return (0);
			index++;
		}
		layer++;
	}
	return (1);
}

int	ft_check_max(char *av[])
{
	int	index;

	index = 1;
	while (av[index])
	{
		if (ft_atoi(av[index]) <= 0)
			return (0);
		index++;
	}
	return (1);
}

int	ft_parser(int ac, char *av[])
{
	while (1)
	{
		if (ac != 5 && ac != 6)
			break ;
		if (!ft_check_digits(av))
			break ;
		if (!ft_check_max(av))
			break ;
		return (1);
	}
	printf("Error argument\n");
	return (0);
}
