/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:36:14 by miniore           #+#    #+#             */
/*   Updated: 2025/04/25 18:48:51 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

uint64_t    ft_get_time(void)
{
    struct timeval  time;

    if(gettimeofday(&time, NULL) == -1)
        return ((uint64_t)-1);
    return((uint64_t)time.tv_sec * 1000 + time.tv_usec / 1000);
}
