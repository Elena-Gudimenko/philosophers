/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:14:29 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/02 19:14:33 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..include/philo.h"

void	error_exit(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
