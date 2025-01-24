/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:53 by miniore           #+#    #+#             */
/*   Updated: 2025/01/24 21:43:05 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    ft_perror(char *error_message)
{
    printf("%s\n", error_message);
    exit(1);
}

void    args_num_parse(int argc)
{
    if(argc < 5 || argc > 6)
        ft_perror("Number of arguments invalid");
}

void    philo_start(t_args *args, int argc, char **argv)
{
    args->philo_num = ft_atoi(argv[1]);
    args->die_t = ft_atoi(argv[2]);
    args->eat_t = ft_atoi(argv[3]);
    args->sleep_t = ft_atoi(argv[4]);
    if(argc == 6)
        args->times_philo_eat = ft_atoi(argv[5]);
    else
        args->times_philo_eat = -1;

}

int check_args(t_args *args)
{
    if(args->philo_num <= 0 || args->die_t <= 0)
}

int main(int argc, char **argv)
{
    t_philo     *args;
    t_philo     **philo;
    
    args_num_parse(argc);
    philo_start(&philo, argc, argv);
    check_args(args);
}