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
		input_int = ft_input_convert_to_int(argc, argv);
		//check duplicate
		ft_input_duplicate_check(input_int, argc);
		//convert int array to rank array
		rank_int = ft_rank(input_int, argc - 1);
		//convert array to double&circle list
		stack_a = (t_stack **)malloc(sizeof(t_stack**));
		head_a = ft_int_to_stack(input_int, rank_int, argc - 1);
		stack_a = &head_a;
		//ft_stack_print(stack_a);
		stack_b = (t_stack **)malloc(sizeof(t_stack**));
		head_b = NULL;
		stack_b = &head_b;

		if (argc < 8 && argc > 3)
			solve_til_six(stack_a, stack_b);

	/*example1 with 2 1 3 6 5 8
	ft_stack_print(stack_a);
	ft_swap(stack_a);
	ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	ft_swap(stack_a);
	ft_push(stack_b, stack_a);
	ft_push(stack_b, stack_a);
	ft_push(stack_b, stack_a);
	ft_printf("stack a is below\n");
	ft_stack_print(stack_a);
	ft_printf("stack b is below\n");
	ft_stack_print(stack_b);
*/
	/*example2 with  3 2 1 0
	ft_reverse_rotate(stack_a);
	ft_push(stack_a, stack_b);
	ft_swap(stack_a);
	ft_reverse_rotate(stack_a);
	ft_push(stack_b, stack_a);
	ft_printf("stack a is below\n");
	ft_stack_print(stack_a);
	ft_printf("stack b is below\n");
	ft_stack_print(stack_b);
	*/

	//scan the number
	//choose argorithm
	//if all sorted
	//print out the actions executed
	//free stacks;
	}
	return (0);
}
