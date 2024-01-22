/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:49 by yublee            #+#    #+#             */
/*   Updated: 2024/01/11 19:49:41 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int 	*input_int;
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack *head_a;
	t_stack *head_b;

	//if no input, give back prompt
	if (argc == 1)
		return (1);
	//if input, convert to int array && check digit
	if (argc > 2)
	{
		input_int = ft_input_convert_to_int(argc, argv);
	//check duplicate
		ft_input_duplicate_check(input_int, argc);
	//convert int array to double&circle list
		stack_a = (t_stack **)malloc(sizeof(t_stack**));
		head_a = ft_int_to_stack(input_int, argc - 1);
		stack_a = &head_a;

	stack_b = (t_stack **)malloc(sizeof(t_stack**));
	head_b = NULL;
	stack_b = &head_b;
//	ft_stack_print(stack_a);
//	ft_stack_print(stack_b);
	ft_push(stack_a, stack_b);
//	printf("%d\n",(*stack_a)->num);
	ft_stack_print(stack_a);
	ft_stack_print(stack_b);

	/*
	ft_stack_print(stack_a);
	ft_printf("after rotate >\n");
//	ft_stack_print(stack_a);
	stack_a = ft_rotate(stack_a);
	ft_stack_print(stack_a);
	ft_printf("after reverse rotate >\n");
	stack_a = ft_reverse_rotate(stack_a);
	ft_stack_print(stack_a);
	ft_printf("after swap >\n");
	stack_a = ft_swap(stack_a);
	ft_stack_print(stack_a);
	ft_printf("done\n");
	*/

//scan the number
//choose argorithm
//if all sorted
//print out the actions executed
//free stacks;
	free(input_int);
	}
	return (0);
}
