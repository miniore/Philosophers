/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:06:58 by miniore           #+#    #+#             */
/*   Updated: 2025/05/07 17:28:42 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

static void    ft_assign_forks(t_args *args)
{
    int i;

    i = 0;
    while (i < args->philo_num)
    {
        if (i == 0)
            args->philos[i].l_fork = &args->philos[args->philo_num - 1].fork;
        else
            args->philos[i].l_fork = &args->philos[i - 1].fork;
        i++;
    }
}

int    philo_start(t_args *args)
{
    int i;

    i = 0;
    args->philos = (t_philo *)ft_calloc(args->philo_num, sizeof(t_philo));
    if(!args->philos)
        return(ft_perror("Malloc error.\n"));
    pthread_mutex_init(&args->lock, NULL);
    pthread_mutex_init(&args->print, NULL);
    while(i < args->philo_num)
    {
        args->philos[i].id = i + 1;
        args->philos[i].eating = 0;
        args->philos[i].num_eat = 0;
        args->philos[i].args = args;
        pthread_mutex_init(&args->philos[i].fork, NULL);
        pthread_mutex_init(&args->philos[i].lock, NULL);
        i++;
    }
    ft_assign_forks(args);
    return(EXIT_SUCCESS);
}

int    rules_start(t_args *args, int argc, char **argv)
{
    args->philo_num = ft_atoi(argv[1]);
    args->die_t = ft_atoi(argv[2]);
    args->eat_t = ft_atoi(argv[3]);
    args->sleep_t = ft_atoi(argv[4]);
    if(argc == 6)
        args->t_2_eat = ft_atoi(argv[5]);
    else
        args->t_2_eat = -1;
    if(args->philo_num <= 0 || args->philo_num > 200 || args->die_t <= 0 ||
        args->eat_t <= 0 || args->sleep_t <= 0 || args->t_2_eat == 0)
        return(ft_perror("Invalid value. Arguments can't be 0 or less.\n"));
    args->dead = 0;
    args->finish = 0;
    return (EXIT_SUCCESS);
}
