
#include "../include/philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

bool    get_bool(t_mtx *mutex, bool *value)
{
	bool	return_value;

	mutex_handle(mutex, LOCK);
	return_value = *value;
	mutex_handle(mutex, UNLOCK);
	return (return_value);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	return_value;

	mutex_handle(mutex, LOCK);
	return_value = *value;
	mutex_handle(mutex, UNLOCK);
	return (return_value);
}

bool	simulation_is_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}