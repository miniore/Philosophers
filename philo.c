/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:53 by miniore           #+#    #+#             */
/*   Updated: 2025/02/13 12:56:29 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    ft_perror(char *error_message)
{
    ft_putstr_fd(error_message, 2);
}

int    args_parse(int argc, char **argv)
{
    int i;
    int j;
    
    if(argc < 5 || argc > 6)
        return(1);
    i = 0;
    while(argv[i++])
    {
        j = 0;
        if(argv[i][0] == '-')
            return(1);
        while(argv[i][++j])
        {
            if(ft_isdigit(argv[i][j]))
                return (1);
        }
    }
    return (0);
}

int    rules_start(t_args *args, int argc, char **argv)
{
    args->philo_num = ft_atoi(argv[1]);
    args->die_t = ft_atoi(argv[2]);
    args->eat_t = ft_atoi(argv[3]);
    args->sleep_t = ft_atoi(argv[4]);
    if(argc == 6)
        args->times_philo_eat = ft_atoi(argv[5]);
    else
        args->times_philo_eat = -1;
    if(args->philo_num <= 0 || args->die_t <= 0 || args->eat_t <= 0 ||
        args->sleep_t <= 0 || args->times_philo_eat <= 0)
        return(1);
    return (0);
}

//void    philo_start(t_args *args, 

int main(int argc, char **argv)
{
    t_args      *args;
    //t_philo     **philo;
    
    if(args_parse(argc, argv))
    {
        ft_perror("Arguments error.\n");
        return(1);
    }
    args = (t_args *)malloc(sizeof(int));
    if(rules_start(args, argc, argv))
    {
        ft_perror("Arguments error.\n");
        return(1);
    }
    philo_start(t_args *args, );
    
    return (0);
}



// NUmerae a cada filosofo en funcion a su posicion en la mesa.
// Administrar, bloquear y desbloquear los mutex para cada filosofo.
// Hacer el reparto de tenedores de manera correcta para que cada filosofo comience la ejecucion con su funcion establecida.