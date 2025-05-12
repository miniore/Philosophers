/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:11:47 by miniore           #+#    #+#             */
/*   Updated: 2025/05/05 19:05:12 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	x;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		x = s[i];
		write (fd, &x, 1);
		i++;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t elem_count, size_t elem_size)
{
	size_t	total_size;
	void	*memory_block;

	total_size = elem_count * elem_size;
	if (elem_count != '\0' && total_size / elem_count != elem_size)
		return (0);
	memory_block = malloc(total_size);
	if (!memory_block)
		return (0);
	if (memory_block != (void *)0)
		ft_memset(memory_block, 0, total_size);
	return (memory_block);
}
