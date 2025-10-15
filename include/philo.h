
#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

# define DEBUG_MODE 0

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

typedef enum e_time_code
{
    SECOND,
    MILLISECOND,
    MICROSECOND
}	t_time_code;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED
}	t_philo_status;

typedef pthread_mutex_t t_mtx;
typedef struct s_table	t_table;


typedef struct  s_fork
{
    t_mtx       fork;
    int         fork_id;
}                   t_fork;

typedef struct  s_philo
{
    int         id;
    long        meals_eaten;
    bool        is_full;
    long        time_last_meal;
    t_fork      *fork_first;
    t_fork      *fork_second;
    pthread_t   thread_id;
    t_mtx       philo_mutex;
    t_table     *table;
}               t_philo;

struct  s_table
{
    long        philo_nbr;
    long        time_to_die;
    long        time_to_eat;
    long        time_to_sleep;
    long        nbr_limit_meals;
    long        start_simulation;
    bool        end_simulation; //philo dies or all philos full
    bool        all_threads_ready;
    long		threads_running_nbr;
    pthread_t   monitor;
    t_mtx		table_mutex;
    t_mtx		write_mutex;
    t_fork      *forks; // array fo forks
    t_philo     *philos;
};

// Init
void    data_init(t_table *table);
void    dinner_start(t_table *table);

// Utils
void	error_exit(const char *message);
long	ft_gettime(t_time_code time_code);
void	precise_usleep(long usec, t_table *table);

//Parsering
void    parse_input(t_table *table, char **argv);

// Wrapper function
void    *ft_malloc(size_t bytes);
void    mutex_handle(t_mtx *mutex, t_opcode opcode);
void    thread_handle(pthread_t *thread, void *(*func)(void *),
		void *data, t_opcode opcode);

// Getters and Setters
void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool    get_bool(t_mtx *mutex, bool *value);
void	set_long(t_mtx *mutex, long *dest, long value);
long	get_long(t_mtx *mutex, long *value);
bool	simulation_is_finished(t_table *table);

//Synchro
void	wait_all_threads(t_table *table);
bool	threads_running(t_mtx *mutex, long *threads, long philo_nbr);
void	increase_long(t_mtx *mutex, long *value);
void	unsync_philos(t_philo *philo);

// Write
void	write_status(t_philo_status status, t_philo *philo, bool debug);

// Monitor
void	*monitor_dinner(void *data);

// Dinner
void	thinking(t_philo *philo, bool pre_simulation);

// Cleaning
void	cleaning(t_table *table);

#endif




