/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:22:56 by ykarabul          #+#    #+#             */
/*   Updated: 2023/04/17 15:20:43 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_end_program(t_env *env)
{
	int	index;
	int	status;

	index = -1;
	while (++index < env->number_of_philos)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			index = -1;
			while (++index < env->number_of_philos)
				kill(env->philos[index].pid, SIGKILL);
			break ;
		}
	}
	sem_close(env->message);
	sem_close(env->check);
	sem_close(env->fork);
	sem_unlink("/print");
	sem_unlink("/check");
	sem_unlink("/forks");
	free(env->philos);
}

void	ft_basis(t_env *env)
{
	int	index;

	index = -1;
	env->start_time = ft_get_time();
	while (++index < env->number_of_philos)
	{
		env->philos[index].time_to_die = env->start_time;
		env->philos[index].pid = fork();
		if (env->philos[index].pid == -1)
			exit(1);
		if (env->philos[index].pid == 0)
			ft_threads(&env->philos[index]);
	}
}

int	main(int ac, char **av)
{
	t_env	env;

	if (!ft_parser(ac, av))
		return (0);
	ft_init(&env, ac, av);
	ft_basis(&env);
	ft_end_program(&env);
	system("leaks philo_bonus");
	exit(1);
	return (0);
}
