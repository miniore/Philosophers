/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:07:34 by miniore           #+#    #+#             */
/*   Updated: 2025/05/05 19:03:03 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

static int	ft_isdigit(int c)
{
	if (c < 47 || c > 58)
		return (1);
	return (0);
}

int    args_parse(int argc, char **argv)
{
    int i;
    int j;
    
    if(argc < 5 || argc > 6)
        return(1);
    i = 1;
    while(argv[i])
    {
        j = 0;
        if(argv[i][0] == '-')
            return(1);
        while(argv[i][j])
        {
            if(ft_isdigit(argv[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
