/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:21:39 by ykarabul          #+#    #+#             */
/*   Updated: 2023/04/17 15:01:57 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int i)
{
	philo->id = i + 1;
	philo->table = table;
	philo->eat_count = 0;
	philo->last_eat = current_time();
	pthread_mutex_init(table->forks + i, NULL);
}

void	fork_init(t_philo *philo, t_table *table, int i)
{
	if (i - 1 < 0)
		philo->rfork = table->forks + (table->number_of_philo - 1);
	else
		philo->rfork = table->forks + (i - 1);
	philo->lfork = table->forks + i;
}

void	start_threads(t_table *table)
{
	int	i;

	pthread_mutex_init(&table->stop_count, NULL);
	pthread_mutex_init(&table->count_eat, NULL);
	pthread_mutex_init(&table->eat_last, NULL);
	pthread_mutex_init(&table->is_print, NULL);
	pthread_mutex_init(&table->is_die, NULL);
	i = -1;
	while (++i < table->number_of_philo)
		philo_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->number_of_philo)
		fork_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->number_of_philo)
		pthread_create(&table->philos[i].thread, NULL,
			philo_routine, table->philos + i);
	die_check(table);
}
