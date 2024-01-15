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

	//if no input, give back prompt
	if (argc == 1)
		return (1);
	//if input, convert to int array && check digit
	input_int = ft_input_convert_to_int(argc, argv);
	//check duplicate
	ft_input_duplicate_check(input_int, argc);
	//convert int array to double&circle list
	stack_a = ft_int_to_stack(input_int, argc);
	printf("num is :%d\n",(*stack_a)->num);
	printf("num is :%d\n",((*stack_a)->next)->num);
	printf("num is :%d\n",(((*stack_a)->next)->next)->num);
	printf("num is :%d\n",((((*stack_a)->next)->next)->next)->num);
	printf("num is :%d\n",(((((*stack_a)->next)->next)->next)->next)->num);
	stack_a = ft_rotate(stack_a);
	printf("after rotate\n");
	printf("num is :%d\n",(*stack_a)->num);
	printf("num is :%d\n",((*stack_a)->next)->num);
	printf("num is :%d\n",(((*stack_a)->next)->next)->num);
	printf("num is :%d\n",((((*stack_a)->next)->next)->next)->num);
	printf("num is :%d\n",(((((*stack_a)->next)->next)->next)->next)->num);
	stack_a = ft_reverse_rotate(stack_a);
	printf("after reverse rotate\n");
	printf("num is :%d\n",(*stack_a)->num);
	printf("num is :%d\n",((*stack_a)->next)->num);
	printf("num is :%d\n",(((*stack_a)->next)->next)->num);
	printf("num is :%d\n",((((*stack_a)->next)->next)->next)->num);
	printf("num is :%d\n",(((((*stack_a)->next)->next)->next)->next)->num);
	stack_a = ft_swap(stack_a);
	printf("after swap\n");
	printf("num is :%d\n",(*stack_a)->num);
	printf("num is :%d\n",((*stack_a)->next)->num);
	printf("num is :%d\n",(((*stack_a)->next)->next)->num);
	printf("num is :%d\n",((((*stack_a)->next)->next)->next)->num);
	printf("num is :%d\n",(((((*stack_a)->next)->next)->next)->next)->num);
	/*
	printf("num is :%d\n",(*stack_a)->num);
	printf("num is :%d\n",((*stack_a)->prev)->num);
	printf("num is :%d\n",(((*stack_a)->prev)->prev)->num);
	printf("num is :%d\n",((((*stack_a)->prev)->prev)->prev)->num);
	*/
//scan the number
//choose argorithm
//if all sorted
//print out the actions executed
//free stacks;
	free(input_int);
	return (0);
}
