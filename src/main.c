/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:49 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 23:43:51 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int 	*input_int;
	int 	*rank_int;
	t_stack *head_a;
	t_stack *head_b;

	if (argc == 1)
		return (1);
	if (argc > 2)
	{
		input_int = (int *)malloc((argc - 1) * sizeof(int));
		if (!input_int)
			exit_with_error("malloc", 1);
		ft_input_convert_to_int(argc, argv, input_int);
		ft_input_duplicate_check(input_int, argc);
		rank_int = ft_rank(input_int, argc - 1);
		head_a = ft_int_to_stack(input_int, rank_int, argc - 1);
		head_b = NULL;
		if (argc < 8 && argc > 3)
			solve_til_six(&head_a, &head_b);
		else
			solve_big_numbers(&head_a, &head_b);
		free_stack(&head_a);
		free_stack(&head_b);
	}
	return (0);
}
