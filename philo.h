/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:58 by miniore           #+#    #+#             */
/*   Updated: 2025/01/24 21:37:08 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_42
# define PHILO_42

typedef struct s_args
{
    int         philo_num;
    int         die_t;
    int         eat_t;
    int         sleep_t;
    int         times_philo_eat;
}   t_args;

typedef struct  s_philo
{
    
}   t_philo;

int	ft_atoi(const char *str);

#endif