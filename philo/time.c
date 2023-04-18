/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:18:56 by ykarabul          #+#    #+#             */
/*   Updated: 2023/04/16 19:46:58 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

uint64_t	time_from_start(t_table *table)
{
	return (current_time() - table->time);
}

void	time_usleep(uint16_t micsec)
{
	uint64_t	current;

	current = current_time();
	while (1)
	{
		if (current_time() - current >= micsec)
			break ;
		usleep(100);
	}
}
