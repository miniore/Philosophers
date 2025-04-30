/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:53 by miniore           #+#    #+#             */
/*   Updated: 2025/04/29 13:08:40 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    ft_exit(t_args *args)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&args->lock);
    while(i < args->philo_num)
    {
        pthread_mutex_destroy(&args->philos[i].fork);
        pthread_mutex_destroy(&args->philos[i].lock);
        i++;
    }
    free(args->philos);
}

void    ft_print_status(t_philo *aux, char *str)
{
    pthread_mutex_lock(&aux->args->lock);
    aux->args->time = ft_get_time() - aux->args->start_time;
    if(ft_strcmp("died.\n", str) == 0)
    {
        printf("%lims: Philo %i %s", aux->args->time, aux->id, str);
        aux->args->dead = 1;
    }
    else
        printf("%lims: Philo %i %s", aux->args->time, aux->id, str);
    pthread_mutex_unlock(&aux->args->lock);
}

int main(int argc, char **argv)
{
    t_args      args;

    if(args_parse(argc, argv))
        return(ft_perror("Arguments error 1.\n"));
    if(rules_start(&args, argc, argv))
        return(ft_perror("Arguments error 2.\n"));
    if(philo_start(&args))
        return(ft_perror("Malloc error.\n"));
    threads_start(&args);
    ft_exit(&args);
    return (EXIT_SUCCESS);
}
