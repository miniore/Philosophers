/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:58 by miniore           #+#    #+#             */
/*   Updated: 2025/04/27 21:05:53 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_42
# define PHILO_42

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

#define TAKE "has taken a fork.\n"
#define EAT "is eating.\n"
#define SLEEP "is sleeping.\n"
#define THINK "is thinking.\n"
#define DEAD "died.\n"



typedef struct  s_args   t_args;
typedef struct  s_philo t_philo;

struct s_args
{
    int         philo_num;
    int         t_2_eat;
    int         dead;
    int         finish;
    long         eat_t;
    long        sleep_t; 
    long         die_t;
    long        start_time;
    long        time;
    pthread_mutex_t lock;
    t_philo     *philos;
};

struct  s_philo
{
    struct s_args   *args;
    pthread_t   ch_thr;
    pthread_t   thr;
    int         id;
    int         eating;
    int         num_eat;
    uint64_t        time_2_die;
    pthread_mutex_t lock;
    pthread_mutex_t fork;
    pthread_mutex_t *l_fork;
};



int    args_parse(int argc, char **argv);

int    rules_start(t_args *args, int argc, char **argv);
int    philo_start(t_args *args);

uint64_t    ft_get_time(void);

void    threads_start(t_args *args);
void    *routine(void *arg);
void    *checker(void *args);

void    eat(t_philo *aux);

void    ft_print_status(t_philo *aux, char *str);

void	ft_putstr_fd(char *s, int fd);
int	    ft_atoi(const char *str);
void	*ft_calloc(size_t elem_count, size_t elem_size);
int     ft_strcmp(char *s1, char *s2);

int    ft_perror(char *error_message);

#endif