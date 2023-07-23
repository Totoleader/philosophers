/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:49:40 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 10:17:01 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	sleep_(t_philos philo)
{
	print_status(philo, "is sleeping");
	wait_(philo.info.time_to_sleep);
	think(philo);
}
