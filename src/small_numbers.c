#include "push_swap.h"

void	solve_three(t_stack **stack_a)
{
	int		rank1;
	int		rank2;
	int		rank3;

	if (((*stack_a)->prev)->location != 3)
		return ;
	rank1 = (*stack_a)->rank;
	rank2 = ((*stack_a)->next)->rank;
	rank3 = ((*stack_a)->prev)->rank;
	if (rank1 < rank3 && rank3 < rank2)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	if (rank2 < rank1 && rank1 < rank3)
		swap_a(stack_a);
	if (rank3 < rank1 && rank1 < rank2)
		reverse_rotate_a(stack_a);
	if (rank2 < rank3 && rank3 < rank1)
		rotate_a(stack_a);
	if (rank3 < rank2 && rank2 < rank1)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}
/*
void	solve_three_b(t_stack **stack_b)
{
	int		rank1;
	int		rank2;
	int		rank3;

	if (((*stack_b)->prev)->location != 2)
		return ;
	rank1 = (*stack_b)->rank;
	rank2 = ((*stack_b)->next)->rank;
	rank3 = ((*stack_b)->prev)->rank;
	if (rank1 < rank3 && rank3 < rank2)
	{
		swap_b(stack_b);
		rotate_b(stack_b);
	}
	if (rank2 < rank1 && rank1 < rank3)
		swap_b(stack_b);
	if (rank3 < rank1 && rank1 < rank2)
		reverse_rotate_b(stack_b);
	if (rank2 < rank3 && rank3 < rank1)
		rotate_b(stack_b);
	if (rank3 < rank2 && rank2 < rank1)
	{
		swap_b(stack_b);
		reverse_rotate_b(stack_b);
	}
}
*/

void	solve_til_six(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (is_stack_sorted(stack_a))
		return ;
	// ft_stack_print(stack_a);
	while (((*stack_a)->prev)->location > 3)
	{
		push_b(stack_a, stack_b);
		// ft_stack_print(stack_a);
	}
	solve_three(stack_a);
	while (*stack_b)
	{
		if ((*stack_b)->rank < (*stack_a)->rank)
			push_a(stack_a, stack_b);
		else if ((*stack_b)->rank > ((*stack_a)->prev)->rank)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
		}
		else
		{
			i = 0;
			// ft_stack_print(stack_a);
			// ft_stack_print(stack_b);
			while (((*stack_b)->rank < ((*stack_a)->prev)->rank ||
				(*stack_b)->rank > (*stack_a)->rank))
			{
			// ft_stack_print(stack_a);
			// ft_printf("\n");
			// ft_stack_print(stack_b);
			// ft_printf("\n");
				rotate_a(stack_a);
			// ft_printf("\n");
			// ft_printf("\n");
			// ft_printf("\n");
				i++;
			}
			push_a(stack_a, stack_b);
			if ((*stack_a)->rank == 1 && !*stack_b)
				return ; 
			while (i--)
				reverse_rotate_a(stack_a);
		}
	}
}

/*
void	solve_four(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (is_stack_sorted(stack_a))
		return ;
	i = 1;
	push_b(stack_a, stack_b);
	solve_three(stack_a);
	if ((*stack_b)->rank == 1)
	{
		push_a(stack_a, stack_b);
		return ;
	}
	while ((*stack_b)->rank - ((*stack_a)->prev)->rank != 1)
	{
		reverse_rotate_a(stack_a);
		i++;
	}
	push_a(stack_a, stack_b);
	while (i--)
		rotate_a(stack_a);
}
*/