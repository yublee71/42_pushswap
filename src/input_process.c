/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:12:26 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 12:56:25 by yublee           ###   ########.fr       */
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
				exit_with_error("Error\n", 1, input_int);
			j++;
		}
		i++;
	}
}

void	ft_input_convert_to_int(int argc, char *argv[], int *input_int)
{
	int	i;
	int	j;
	int	error_flag;

	i = 0;
	error_flag = 0;
	while (++i < argc)
	{
		if (!ft_strlen(argv[i]))
			exit_with_error("Error\n", 1, input_int);
		j = 0;
		if (argv[i][j] == '0' && argv[i][j + 1])
			error_flag = 1;
		if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])
			&& argv[i][j + 1] != '0')
			j++;
		while (argv[i][j])
			if (error_flag || !ft_isdigit(argv[i][j++]))
				exit_with_error("Error\n", 1, input_int);
		if ((long)ft_atoi(argv[i]) != ft_long_atoi(argv[i]))
			exit_with_error("Error\n", 1, input_int);
		input_int[i - 1] = ft_atoi(argv[i]);
	}
}
