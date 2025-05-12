/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:14:46 by miniore           #+#    #+#             */
/*   Updated: 2025/05/07 13:56:46 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	get_forks(t_philo *aux)
{
	if (aux->id % 2 == 0)
	{
		pthread_mutex_lock(aux->l_fork);
		if (!is_dead(aux))
			ft_print_status(aux, TAKE);
		pthread_mutex_lock(&aux->fork);
		if (!is_dead(aux))
			ft_print_status(aux, TAKE);
	}
	else
	{
		pthread_mutex_lock(&aux->fork);
		if (!is_dead(aux))
			ft_print_status(aux, TAKE);
		pthread_mutex_lock(aux->l_fork);
		if (!is_dead(aux))
			ft_print_status(aux, TAKE);
	}
}

void	leave_forks(t_philo *aux)
{
	pthread_mutex_unlock(&aux->fork);
	pthread_mutex_unlock(aux->l_fork);
	if (!is_dead(aux))
		ft_print_status(aux, SLEEP);
	usleep(aux->args->sleep_t * (uint64_t)1000);
}

void	eat(t_philo *aux)
{
	get_forks(aux);
	pthread_mutex_lock(&aux->lock);
	aux->eating = 1;
	aux->time_2_die = ft_get_time() + aux->args->die_t;
	if (!is_dead(aux))
		ft_print_status(aux, EAT);
	usleep(aux->args->eat_t * (uint64_t)1000);
	aux->num_eat++;
	aux->eating = 0;
	pthread_mutex_unlock(&aux->lock);
	leave_forks(aux);
}
