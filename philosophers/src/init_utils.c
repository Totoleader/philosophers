/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:48:37 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 13:31:20 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*malloc_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = NULL;
	while (!mutex)
		mutex = malloc(sizeof(pthread_mutex_t));
	return (mutex);
}

int	*malloc_int(void)
{
	int	*integer;

	integer = NULL;
	while (!integer)
		integer = ft_calloc(1, sizeof(int));
	return (integer);
}

t_philos	*malloc_philos(t_info info)
{
	t_philos		*philos;

	philos = NULL;
	while (!philos)
		philos = ft_calloc(sizeof(t_philos), info.nb_of_philo);
	return (philos);
}

unsigned long	*malloc_ul(void)
{
	unsigned long	*ul;

	ul = NULL;
	while (!ul)
	{
		ul = ft_calloc(1, sizeof(unsigned long));
	}
	return (ul);
}
