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

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}

bool	threads_running(t_mtx *mutex, long *threads, long philo_nbr)
{
	bool	res;

	res = false;
	mutex_handle(mutex, LOCK);
	if (*threads == philo_nbr)
		res = true;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

void	increase_long(t_mtx *mutex, long *value)
{
	mutex_handle(mutex, LOCK);
	(*value)++;
	mutex_handle(mutex, UNLOCK);
}