/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:24:46 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 17:24:46 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_rank(int *input_int, int size)
{
	int	i;
	int	j;
	int	r;
	int	*rank;

	i = 0;
	rank = (int *)malloc(size * sizeof(int));
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