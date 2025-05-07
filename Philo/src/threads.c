/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:13:55 by miniore           #+#    #+#             */
/*   Updated: 2025/05/07 17:53:00 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

void    ft_one_philo(t_philo *philo)
{
    pthread_mutex_lock(&philo->fork);
    ft_print_status(philo, TAKE);
    pthread_mutex_unlock(&philo->fork);
    usleep(philo->args->die_t * (uint64_t)1000);
    ft_print_status(philo, DEAD);
    return ;
}

void    *checker(void *args)
{
    t_philo  *aux;
    int     flag;

    aux = (t_philo *)args;
    flag = 0;
    while(!is_dead(aux) && !flag)
    {
        usleep((uint64_t)1000);
        pthread_mutex_lock(&aux->lock);
        if(aux->time_2_die && ft_get_time() >= aux->time_2_die && !aux->eating)
            ft_print_status(aux, DEAD);
        if(aux->num_eat == aux->args->t_2_eat && !flag)
        {
            flag++;
            pthread_mutex_lock(&aux->args->lock);
            aux->args->finish++;
            if(aux->args->finish >= aux->args->philo_num)
                aux->args->dead = 1;
            pthread_mutex_unlock(&aux->args->lock);
        }
        pthread_mutex_unlock(&aux->lock);
    }
    return((void *)0);
}

void    *routine(void *arg)
{
    t_philo  *aux;

    aux = (t_philo *)arg;
    if(aux->id % 2 == 0)
        usleep(aux->args->eat_t * (uint64_t)1000);
    if(pthread_create(&aux->ch_thr, NULL, &checker, arg))
        return((void *)1);
    while(!is_dead(aux))
    {
        eat(aux);
        if(!is_dead(aux))
            ft_print_status(aux, THINK);
        if(aux->num_eat == aux->args->t_2_eat)
            break;
    }
    if(pthread_join(aux->ch_thr, NULL))
        return((void *)1);
    return((void *)0);
}

void    threads_start(t_args *args)
{
    int i;

    args->start_time = ft_get_time();
    i = 0;
    if(args->philo_num == 1)
        return(ft_one_philo(args->philos));
    while(i < args->philo_num)
    {
        if(pthread_create(&args->philos[i].thr, NULL, &routine, &args->philos[i]))
            return((void)ft_perror("Thread create failed.\n"));
        usleep((uint64_t)1000);
        i++;
    }
    i = 0;
    while(i < args->philo_num)
    {
        if(pthread_join(args->philos[i].thr, NULL))
            return((void)ft_perror("Thread join failed.\n"));
        i++;
    }
}
