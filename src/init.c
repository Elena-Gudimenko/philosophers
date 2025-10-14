/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:36:54 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/04 14:31:25 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->fork_first = &forks[(philo_position + 1) % philo_nbr];
	philo->fork_second = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->fork_first = &forks[philo_position];
		philo->fork_second = &forks[(philo_position + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->is_full = false;
		philo->meals_eaten = 0;
		philo->table = table;
		mutex_handle(&philo->philo_mutex, INIT);
		assign_forks(philo, table->forks, i);
	}
}

void    data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->threads_running_nbr = 0;
	table->philos = ft_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = ft_malloc(sizeof(t_fork) * table->philo_nbr);
	mutex_handle(&table->table_mutex, INIT);
	mutex_handle(&table->write_mutex, INIT);
	while (++i < table->philo_nbr)
	{
		mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}