/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:12:18 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 10:23:01 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//called when there is error in parse.c
void	input_error(void)
{
	ft_putendl_fd("Input error.", STDERR_FILENO);
}
