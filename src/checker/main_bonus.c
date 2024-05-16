/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:49 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 16:35:16 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	exec_operation(int i, t_stack **stack_a, t_stack **stack_b)
{
	if (i == 0)
		push_a(stack_a, stack_b);
	else if (i == 1)
		push_b(stack_a, stack_b);
	else if (i == 2)
		swap_a(stack_a);
	else if (i == 3)
		swap_a(stack_b);
	else if (i == 4)
		swap_ab(stack_a, stack_b);
	else if (i == 5)
		rotate_a(stack_a);
	else if (i == 6)
		rotate_b(stack_b);
	else if (i == 7)
		rotate_ab(stack_a, stack_b);
	else if (i == 8)
		reverse_rotate_a(stack_a);
	else if (i == 9)
		reverse_rotate_b(stack_b);
	else if (i == 10)
		reverse_rotate_ab(stack_a, stack_b);
}

static void	find_and_exec_operation(t_stack **stack_a, t_stack **stack_b)
{
	char		*buf;
	static char	*op[11] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n",
	"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int			i;

	while (1)
	{
		buf = get_next_line(0);
		if (!buf)
			break ;
		i = 0;
		while (i < 11)
		{
			if (!ft_strncmp(buf, op[i], ft_strlen(op[i])))
				break ;
			i++;
		}
		free(buf);
		if (i < 11)
			exec_operation(i, stack_a, stack_b);
		else
			exit_with_error("Error\n", 1, NULL);
	}
}

int	main(int argc, char *argv[])
{
	int		*input_int;
	int		*rank_int;
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc == 1)
		return (1);
	input_int = (int *)malloc((argc - 1) * sizeof(int));
	if (!input_int)
		exit_with_error("malloc\n", 1, NULL);
	input_convert_to_int(argc, argv, input_int);
	input_duplicate_check(input_int, argc);
	rank_int = ft_rank(input_int, argc - 1);
	head_a = int_to_stack(input_int, rank_int, argc - 1);
	head_b = NULL;
	find_and_exec_operation(&head_a, &head_b);
	if (!is_stack_sorted(&head_a) || head_b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(&head_a);
	free_stack(&head_b);
}
