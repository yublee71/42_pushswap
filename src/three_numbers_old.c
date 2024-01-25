#include "push_swap.h"

/*
void    print_bits(unsigned int octet)
{
	unsigned int	n;
	int				i;

	unsigned int reversed;
	unsigned char inByte0 = (octet & 0x000000FF);
	unsigned char inByte1 = (octet & 0x0000FF00) >> 8;
	unsigned char inByte2 = (octet & 0x00FF0000) >> 16;
	unsigned char inByte3 = (octet & 0xFF000000) >> 24;
	reversed = (inByte0 << 24) | (inByte1 << 16) | (inByte2 << 8) | (inByte3);

	n = INT_MIN; 
	i = 0;
	while (i++ < 32)
	{
		if (n & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		n = n >> 1;
	}
}
*/

unsigned int make_hash(int* rank)
{
	unsigned int op_code;
	unsigned char inByte0 = 0x00000000;
	unsigned char inByte1 = (rank[0] & 0x000000FF);
	unsigned char inByte2 = (rank[1] & 0x000000FF);
	unsigned char inByte3 = (rank[2] & 0x000000FF);
	op_code = (inByte0 << 24) | (inByte1 << 16) | (inByte2 << 8) | (inByte3);
	return(op_code);
}

void	solve_three(unsigned int identifier)
{
	t_id	ids[6] = {
		{0x00010203, ""},
		{0x00010302, "sa\nra\n"},
		{0x00020103, "sa\n"},
		{0x00020301, "rra\n"},
		{0x00030102, "ra\n"}
		{0x00030201, "sa\nrra\n"},
	};
	int i;

	i = 0;
	while (i < 6)
	{
		if (identifier == ids[i].identifier)
		{
			ft_printf("%s", ids[i].answer);
			return ;
		}
		i++;
	}
	ft_printf("error\n");
}
/*
#include <stdio.h>
int	main()
{
	int rank[3] = {3, 1, 2};
	print_bits(make_hash(rank));
	printf("%s", solve_three(make_hash(rank)));
}
*/