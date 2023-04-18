/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:43:37 by ykarabul          #+#    #+#             */
/*   Updated: 2023/04/17 15:09:24 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philo)
	{
		if (table->number_of_philo == 1)
			pthread_detach(table->philos[i].thread);
		pthread_join(table->philos[i].thread, NULL);
	}
	pthread_mutex_destroy(&table->stop_count);
	pthread_mutex_destroy(&table->count_eat);
	pthread_mutex_destroy(&table->eat_last);
	pthread_mutex_destroy(&table->is_die);
	pthread_mutex_destroy(&table->is_print);
	i = 0;
	while (i < table->number_of_philo)
		pthread_mutex_destroy(&table->forks[i++]);
	free (table->forks);
	free (table->philos);
	free (table);
}

int	main(int ac, char **av)
{
	t_table	*table;
	int		i;

	table = parse(ac, av);
	if (table->number_of_philo == 1)
	{
		time_usleep(table->time_to_die);
		i = time_from_start(table);
		printf("\033[0;36m%d \033[0;32m%d %s\033[0m\n", 0, 1, TAKEN_FORK);
		printf("\033[0;36m%d \033[0;32m%d %s\033[0m\n", i, 1, DIE);
		free (table->forks);
		free (table->philos);
		free (table);
	}
	if (table != NULL)
	{
		if (table->number_of_philo > 1)
		{
			start_threads(table);
			end_threads(table);
		}
	}
	system("leaks philo");
	return (0);
}
