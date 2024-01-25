#include "push_swap.h"

void	solve_three(int *rank)
{
	int		cases;
	char	*solutions[6] = {"", "sa\nra\n", "sa\n", "rra\n", "ra\n", "sa\nrra\n"};

	cases = 0;
	if (rank[0] < rank[1] && rank[1] < rank[2])
		;
	else if (rank[0] < rank[2] && rank[2] < rank[1])
		cases = 1;
	else if (rank[1] < rank[0] && rank[0] < rank[2])
		cases = 2;
	else if (rank[2] < rank[0] && rank[0] < rank[1])
		cases = 3;
	else if (rank[1] < rank[2] && rank[2] < rank[0])
		cases = 4;
	else if (rank[2] < rank[1] && rank[1] < rank[0])
		cases = 5;
	else
		ft_printf("error\n");
	ft_printf("%s", solutions[cases]);
}
