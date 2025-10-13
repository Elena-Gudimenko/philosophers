/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:41:52 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/04 15:44:28 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

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
    t_fork      *forks; // array fo forks
    t_philo     *philos;
};

// Init
void    data_init(t_table *table); 

// Utils
void	error_exit(const char *message);

//Parsering
void    parse_input(t_table *table, char **argv);

// Wrapper function
void    *ft_malloc(size_t bytes);
void    mutex_handle(t_mtx *mutex, t_opcode opcode);
void    thread_handle(pthread_t *thread, void *(*func)(void *),
		void *data, t_opcode opcode);



