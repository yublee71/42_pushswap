/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:49 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 23:37:05 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int 	*input_int;
	int 	*rank_int;
	t_stack **stack_a;
	t_stack *head_a;
	t_stack **stack_b;
	t_stack *head_b;

	//if no input, give back prompt
	if (argc == 1)
		return (1);
	//if input number is more than 1,
	if (argc > 2)
	{
		//convert to int array && check digit
		input_int = (int *)malloc((argc - 1) * sizeof(int));
		if (!input_int)
			exit_with_error("malloc", 1);
		ft_input_convert_to_int(argc, argv, input_int);
		//check duplicate
		ft_input_duplicate_check(input_int, argc);
		//convert int array to rank array
		rank_int = ft_rank(input_int, argc - 1);
		//convert array to double&circle list
		head_a = ft_int_to_stack(input_int, rank_int, argc - 1);
		stack_a = &head_a;
		head_b = NULL;
		stack_b = &head_b;
		// ft_stack_print(stack_a);
		// ft_printf("===============\n");
		// reverse_rotate_a(stack_a);
		// reverse_rotate_a(stack_a);
		// reverse_rotate_a(stack_a);
		// reverse_rotate_a(stack_a);
		// swap_a(stack_a);
		// swap_a(stack_a);
		// ft_stack_print(stack_a);
		// ft_printf("===============\n");
		// push_b(stack_a, stack_b);
		// push_a(stack_a, stack_b);
		// ft_stack_print(stack_b);
		// ft_printf("===============\n");
		// ft_stack_print(stack_a);
		// ft_printf("===============\n");
		if (argc < 8 && argc > 3)
			solve_til_six(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);

	//scan the number
	//choose argorithm
	//if all sorted
	//print out the actions executed
	//free stacks;
	}
	return (0);
}
