/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:07:34 by miniore           #+#    #+#             */
/*   Updated: 2025/05/07 17:57:06 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

static int	ft_isdigit(int c)
{
	if (c < 47 || c > 58)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int    args_parse(int argc, char **argv)
{
    int i;
    int j;
    
    if(argc < 5 || argc > 6)
        return(ft_perror("Invalid number of arguments.\n"));
    i = 1;
    while(argv[i])
    {
        j = 0;
        if(argv[i][0] == '-')
            return(ft_perror("Invalid value. Arguments can't be 0 or less.\n"));
        while(argv[i][j])
        {
            if(ft_isdigit(argv[i][j]))
                return (EXIT_FAILURE);
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}
