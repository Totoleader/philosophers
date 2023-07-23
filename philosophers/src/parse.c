/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:12:34 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 13:32:47 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//parses user input into the info struct
t_info	parse_info(int argc, char **argv)
{
	t_info		info;
	long long	data[4];
	int			i;

	i = 0;
	while (++i <= 4)
	{
		data[i - 1] = ft_atoi(argv[i]);
		if (data[i - 1] > INT_MAX || data[i - 1] < 0 || data[0] == 0)
			data[0] = -1;
	}
	info.nb_of_philo = (int)data[0];
	info.time_to_die = (int)data[1];
	info.time_to_eat = (int)data[2];
	info.time_to_sleep = (int)data[3];
	info.nb_of_eat = -1;
	if (argc == 6 && data[0] > 0)
	{
		data[0] = ft_atoi(argv[5]);
		if (data[0] > INT_MAX || data[0] < 0)
			info.nb_of_philo = -1;
		info.nb_of_eat = (int)data[0];
	}
	info.time_init = time_() + 2000;
	return (info);
}
