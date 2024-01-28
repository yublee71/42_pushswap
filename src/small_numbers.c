#include "push_swap.h"

void	solve_three(t_stack **stack_a)
{
	int		rank1;
	int		rank2;
	int		rank3;
	t_stack	*temp;
	
	temp = *stack_a;
	rank1 = temp->rank;
	rank2 = (temp->next)->rank;
	rank3 = (temp->prev)->rank;
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