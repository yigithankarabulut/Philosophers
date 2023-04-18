/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:24:05 by ykarabul          #+#    #+#             */
/*   Updated: 2023/04/17 12:13:34 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_forks(t_philos *philos)
{
	sem_wait(philos->env->fork);
	sem_wait(philos->env->message);
	printf("\033[0;36m%ld\t\033[0;32m%d taken fork\033[0m\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
	sem_wait(philos->env->fork);
	sem_wait(philos->env->message);
	printf("\033[0;36m%ld\t\033[0;32m%d taken fork\033[0m\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
}

void	ft_eat(t_philos *philos)
{
	sem_wait(philos->env->message);
	printf("\033[0;36m%ld\t\033[0;32m%d is eating\033[0m\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
	ft_usleep(ft_get_time(), philos->env->time_eat);
	sem_wait(philos->env->check);
	philos->time_to_die = ft_get_time();
	philos->eaten_meals++;
	sem_post(philos->env->check);
	sem_post(philos->env->fork);
	sem_post(philos->env->fork);
}

void	ft_sleep(t_philos *philos)
{
	sem_wait(philos->env->message);
	printf("\033[0;36m%ld\t\033[0;32m%d is sleeping\033[0m\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
	ft_usleep(ft_get_time(), philos->env->time_sleep);
}

void	ft_think(t_philos *philos)
{
	sem_wait(philos->env->message);
	printf("\033[0;36m%ld\t\033[0;32m%d is thinking\033[0m\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
}
