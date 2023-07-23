/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:00:00 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 13:58:18 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <libc.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philosophers_info
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_eat;
	unsigned long	time_init;
}					t_info;

typedef struct philosophers_philos
{
	int				id;
	int				*nb_of_meals;
	unsigned long	*last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*last_meal_mutex;
	t_info			info;
	pthread_mutex_t	*print_mutex;
}					t_philos;

t_info				parse_info(int argc, char **argv);

void				input_error(void);

unsigned long		time_(void);
unsigned long		timestamp(unsigned long time_init);
unsigned long		time_since_last_meal(t_philos philo);

t_philos			*init_philos(t_info info);
void				launch_threads(t_philos *philos);

void				print_status(t_philos philo, char *str);

void				think(t_philos philo);
void				eat(t_philos philo);
void				sleep_(t_philos philo);

void				wait_(int time_to_wait);
void				*life_of_a_philo(void *package);
void				*faucheuse(void *package);

pthread_mutex_t		*malloc_mutex(void);
int					*malloc_int(void);
t_philos			*malloc_philos(t_info info);
unsigned long		*malloc_ul(void);

#endif