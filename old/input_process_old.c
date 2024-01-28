/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:12:26 by yublee            #+#    #+#             */
/*   Updated: 2024/01/11 20:45:10 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

bool	ft_input_duplicate_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strncmp(argv[i], argv[j], 11))
			{
				ft_printf("error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

bool	ft_input_digit_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0 && argv[i][j + 1] && ft_isdigit(argv[i][j + 1]))
			{
				j++;
				continue;
			}
			if (!ft_isdigit(argv[i][j]) || j > 10)
			{
				ft_printf("error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

bool	ft_is_input_valid(int argc, char *argv[])
{
	if (argc == 1)
	//give prompt back??
		exit (1);
	else
	{
		if (ft_input_digit_check(argc, argv) &&
				ft_input_duplicate_check(argc, argv))
			return (1);
	}
	return (0);
}
