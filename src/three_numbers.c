#include "push_swap.h"

bool	solve_three(int *rank)
{
	int			cases;
	static char	*solutions[6] = {
		"sa\nra\n", "sa\n", "rra\n", "ra\n", "sa\nrra\n"
	};

	cases = 0;
	if (rank[0] < rank[1] && rank[1] < rank[2])
		return (0);
	else if (rank[0] < rank[2] && rank[2] < rank[1])
		cases = 0;
	else if (rank[1] < rank[0] && rank[0] < rank[2])
		cases = 1;
	else if (rank[2] < rank[0] && rank[0] < rank[1])
		cases = 2;
	else if (rank[1] < rank[2] && rank[2] < rank[0])
		cases = 3;
	else if (rank[2] < rank[1] && rank[1] < rank[0])
		cases = 4;
	else
		ft_printf("error\n");
	ft_printf("%s", solutions[cases]);
	return (1);
}

void	solve_four(int *rank)
{
	if (rank[0] == 1 && rank[1] == 2 && rank[2] == 3 && rank[3] == 4)
		return ;
	if (rank[1] == 1)
		ft_printf("ra\n");
	if (rank[2] == 1)
		ft_printf("ra\nra\n");
	if (rank[3] == 1)
		ft_printf("rra\n");
	ft_printf("pb\n");
	solve_three(&rank[1]);
	ft_printf("pa\n");
}