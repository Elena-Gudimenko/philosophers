
#include "../include/philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo, long elapsed)
{
	if (status == TAKE_FIRST_FORK && !simulation_is_finished(philo->table))
		printf("%-6ld %d has taken the 1st fork"
			"\t\t\tn: %d\n", elapsed, philo->id, philo->fork_first->fork_id);
	else if (status == TAKE_SECOND_FORK
		&& !simulation_is_finished(philo->table))
		printf("%-6ld %d has taken the 2nd fork"
			"\t\t\tn: %d\n", elapsed, philo->id, philo->fork_second->fork_id);
	else if (status == EATING && !simulation_is_finished(philo->table))
		printf("%-6ld %d is eating"
			"\t\t\t %ld\n", elapsed, philo->id, philo->meals_eaten);
	else if (status == SLEEPING && !simulation_is_finished(philo->table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_is_finished(philo->table))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%-6ld %d died\n", elapsed, philo->id);
}


void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = ft_gettime(MILLISECOND) - philo->table->start_simulation;
	if (philo->is_full)
		return ;
	mutex_handle(&philo->table->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
    {
        if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
			&& !simulation_is_finished(philo->table))
			printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
		else if (status == EATING && !simulation_is_finished(philo->table))
			printf("%-6ld %d is eating\n", elapsed, philo->id);
		else if (status == SLEEPING && !simulation_is_finished(philo->table))
			printf("%-6ld %d is sleeping\n", elapsed, philo->id);
		else if (status == THINKING && !simulation_is_finished(philo->table))
			printf("%-6ld %d is thinking\n", elapsed, philo->id);
		else if (status == DIED)
			printf("%-6ld %d died\n", elapsed, philo->id);
    }
    mutex_handle(&philo->table->write_mutex, UNLOCK);
}


