/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:22:50 by ykarabul          #+#    #+#             */
/*   Updated: 2023/04/17 11:30:10 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_init_forks(t_env *env)
{
	sem_unlink("/check");
	sem_unlink("/fork");
	sem_unlink("/message");
	env->check = sem_open("/check", O_CREAT, 0666, 1);
	env->fork = sem_open("/fork", O_CREAT, 0666, env->number_of_philos);
	env->message = sem_open("/message", O_CREAT, 0666, 1);
	sem_unlink("/check");
	sem_unlink("/fork");
	sem_unlink("/message");
	if (env->check == SEM_FAILED || env->fork == SEM_FAILED \
	|| env->message == SEM_FAILED)
		return (0);
	return (1);
}

int	ft_init_philos(t_env *env)
{
	int	i;

	i = -1;
	env->philos = malloc(sizeof(t_philos) * env->number_of_philos);
	if (!env->philos)
		return (0);
	env->dead = 0;
	while (++i < env ->number_of_philos)
	{
		env->philos[i].eaten_meals = 0;
		env->philos[i].number = i + 1;
		env->philos[i].env = env;
		env->philos->last_eat = 0;
		env->philos[i].must_eat = env->must_eat;
	}
	return (1);
}

void	ft_init(t_env *env, int argc, char **argv)
{
	env->number_of_philos = ft_atoi(argv[1]);
	env->time_die = ft_atoi(argv[2]);
	env->time_eat = ft_atoi(argv[3]);
	env->time_sleep = ft_atoi(argv[4]);
	env->must_eat = 2147483647;
	if (argc == 6)
		env->must_eat = ft_atoi(argv[5]);
	if (!ft_init_philos(env))
	{
		printf("Malloc error\n");
		exit(0);
	}
	if (!ft_init_forks(env))
	{
		printf("Semaphore error\n");
		exit(0);
	}
}
