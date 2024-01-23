#include "push_swap.h"

int	*ft_rank(int *input_int, int size)
{
	int	i;
	int	j;
	int	r;
	int	*rank;

	i = 0;
	rank = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		r = 0;
		j = 0;
		while (j < size)
		{
			if (j != i && input_int[j] < input_int[i])
				r++;
			j++;
		}
		rank[i++] = r;
	}
	return (rank);
}