/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:12:26 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 17:39:45 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_input_duplicate_check(int *input_int, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (input_int[i] == input_int[j])
			{
				free(input_int);
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}
// needs check for max int
int	*ft_input_convert_to_int(int argc, char *argv[])
{
	int	i;
	int	j;
	int	error_flag;
	int	*input_int;

	i = 1;
	input_int = (int *)malloc((argc - 1) * sizeof(int));
	while (i < argc)
	{
		j = 0;
		error_flag = 0;
		if (argv[i][j] == '0' && argv[i][j + 1])
			error_flag = 1;
		if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]) 
			&& argv[i][j + 1] != '0')
			j++;
		while (argv[i][j])
		{
			if (error_flag || !ft_isdigit(argv[i][j]))
			{
				free(input_int);
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		input_int[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (input_int);
}
