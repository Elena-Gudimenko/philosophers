/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:14:48 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/03 16:53:43 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..include/philo.h"

static inline bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char   *input_is_valid(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Give me only positive numbers.\n");
	if (!is_digit(*str))
		error_exit("The input is not correct digit.\n");
	number = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		error_exit("The number is too big, it's must be in limit of INT_MAX");
	return (number);
}
static long ft_atol(const char *str)
{
    long	num;

	num = 0;
	str = input_is_valid(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
		error_exit("The number is too big, it's must be in limit of INT_MAX");
	return (num);
}

void    parse_input(t_table *table, char **argv)
{
    table->philo_nbr = ft_atol(argv[1]);
    table->time_to_die = ft_atol(argv[2]) * 1e3; // 1e3 = 1000
    table->time_to_eat = ft_atol(argv[3]) * 1e3;
    table->time_to_sleep = ft_atol(argv[4]) * 1e3;
    if (table->time_to_die < 6e4
        || table->time_to_eat < 6e4
        || table->time_to_sleep < 6e4)
        error_exit("The time must be greater 60ms.\n");
    if (argv[5])
        table->nbr_limit_meals = ft_atol(argv[5]);
    else
        table->nbr_limit_meals = -1;
}