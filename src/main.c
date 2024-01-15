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

	if (argc == 1)
		return (1);
	input_int = ft_input_convert_to_int(argc, argv);
	ft_input_duplicate_check(input_int, argc);
	stack_a = ft_int_to_stack(input_int, argc);
//check error if error
//	if (ft_input_check(argc, argv))
//		ft_get_list(argc, argv);
//if no error creating stack a from input
//	ft_create_stack(argv);
//scan the number
//choose argorithm
//if all sorted
//print out the actions executed
	free(stack_a);
	return (0);
}
