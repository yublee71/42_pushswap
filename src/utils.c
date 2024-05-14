/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:19:47 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 23:44:44 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(const char *str, int exit_no)
{
	ft_printf("%s", str);
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
		rank[i++] = r;
	}
	return (rank);
}
