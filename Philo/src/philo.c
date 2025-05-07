/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:53 by miniore           #+#    #+#             */
/*   Updated: 2025/05/07 17:28:36 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

void    ft_exit(t_args *args)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&args->lock);
    pthread_mutex_destroy(&args->print);
    while(i < args->philo_num)
    {
        pthread_mutex_destroy(&args->philos[i].fork);
        pthread_mutex_destroy(&args->philos[i].lock);
        i++;
    }
    free(args->philos);
    args->philos = NULL;
}

void    ft_print_status(t_philo *aux, char *str)
{
    pthread_mutex_lock(&aux->args->print);
    aux->args->time = ft_get_time() - aux->args->start_time;
    if(ft_strcmp("died.\n", str) == 0)
    {
        if(!is_dead(aux))
        {
            pthread_mutex_lock(&aux->args->lock);
            aux->args->dead = 1;
            pthread_mutex_unlock(&aux->args->lock);
            printf("%lims: Philo %i %s", aux->args->time, aux->id, str);
        }
    }
    else
        printf("%lims: Philo %i %s", aux->args->time, aux->id, str);
    pthread_mutex_unlock(&aux->args->print);
}

int is_dead(t_philo *aux)
{
    int flag;

    pthread_mutex_lock(&aux->args->lock);
    flag = aux->args->dead;
    pthread_mutex_unlock(&aux->args->lock);
    return (flag);
}

int main(int argc, char **argv)
{
    t_args      args;

    if(args_parse(argc, argv))
        return(EXIT_FAILURE);
    if(rules_start(&args, argc, argv))
        return(EXIT_FAILURE);
    if(philo_start(&args))
        return(EXIT_FAILURE);
    threads_start(&args);
    ft_exit(&args);
    return (EXIT_SUCCESS);
}
