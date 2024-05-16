/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:19:47 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 12:48:14 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(const char *str, int exit_no, int *input_int)
{
	write(2, str, ft_strlen(str));
	if (input_int)
		free(input_int);
	exit(exit_no);
}

int	*ft_rank(int *input_int, int size)
{
	int	i;
	int	j;
	int	r;
	int	*rank;

	i = 0;
	rank = (int *)malloc(size * sizeof(int));
	if (!rank)
		exit_with_error("malloc\n", 1); //needs to free input as well?
	while (i < size)
	{
		j = 0;
		r = 1;
		while (j < size)
		{
			if (j != i && input_int[j] < input_int[i])
				r++;
			j++;
		}
		rank[i] = r;
		i++;
	}
	return (rank);
}

long	ft_long_atoi(const char *nptr)
{
	long	nbr;
	long	minus;

	nbr = 0;
	minus = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr *= 10;
		nbr += *nptr - '0';
		nptr++;
	}
	return (minus * nbr);
}
