/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:58 by miniore           #+#    #+#             */
/*   Updated: 2025/02/01 12:14:00 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_42
# define PHILO_42

#include <stdlib.h>
#include <unistd.h>

typedef struct s_args
{
    int         philo_num;
    int         die_t;
    int         eat_t;
    int         sleep_t;
    int         times_philo_eat;
    t_philo     *philos;
}               t_args;

typedef struct  s_philo
{
    int         numb;
}   t_philo;

void	ft_putstr_fd(char *s, int fd);
int	    ft_isdigit(int c);
int	    ft_atoi(const char *str);

#endif