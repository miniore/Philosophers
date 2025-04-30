/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:14:46 by miniore           #+#    #+#             */
/*   Updated: 2025/04/30 15:12:51 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    get_forks(t_philo *aux)
{
    pthread_mutex_lock(&aux->fork);
    if(aux->args->dead == 0)
        ft_print_status(aux, TAKE);
    pthread_mutex_lock(aux->l_fork);
    if(aux->args->dead == 0)
        ft_print_status(aux, TAKE);
}

void    leave_forks(t_philo *aux)
{
    pthread_mutex_unlock(&aux->fork);
    pthread_mutex_unlock(aux->l_fork);
    if(aux->args->dead == 0)
        ft_print_status(aux, SLEEP);
    usleep(aux->args->sleep_t * 1000);
}

void    eat(t_philo *aux)
{
    get_forks(aux);
    pthread_mutex_lock(&aux->lock);
    aux->eating = 1;
    aux->time_2_die = ft_get_time() + aux->args->die_t;
    if(aux->args->dead == 0)
        ft_print_status(aux, EAT);
    usleep(aux->args->eat_t * 1000);
    aux->num_eat++;
    aux->eating = 0;
    printf("Philo %d eat %d times\n", aux->id, aux->num_eat);
    pthread_mutex_unlock(&aux->lock);
    leave_forks(aux);
}
