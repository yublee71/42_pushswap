#include <limits.h>
#include <unistd.h>
void    print_bits(unsigned int octet)
{
	unsigned int	n;
	int				i;
/*
	unsigned int reversed;
	unsigned char inByte0 = (octet & 0x000000FF);
	unsigned char inByte1 = (octet & 0x0000FF00) >> 8;
	unsigned char inByte2 = (octet & 0x00FF0000) >> 16;
	unsigned char inByte3 = (octet & 0xFF000000) >> 24;
	reversed = (inByte0 << 24) | (inByte1 << 16) | (inByte2 << 8) | (inByte3);
*/
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

unsigned int make_hash(int* rank)
{
	unsigned int op_code;
	unsigned char inByte0 = (rank[0] & 0x000000FF);
	unsigned char inByte1 = (rank[1] & 0x000000FF);
	unsigned char inByte2 = (rank[2] & 0x000000FF);
	unsigned char inByte3 = 0x00000000;
	op_code = (inByte3 << 24) | (inByte2 << 16) | (inByte1 << 8) | (inByte0);
	return(op_code);
}

typedef struct s_three_numbers
{
	unsigned int	identifier;
	char			*answer;
} t_id;


char	*solve_three(unsigned int identifier)
{
	t_id	ids[6] = {
		{0x00020100, "sa\nsb\nrra\n"}
	};

	// char	*answers[6] = {
	// 	"sa\nsb\nrra\n"
	// };
	// int cases[6][3] = {
	// 	{0, 1, 2},
	// 	{0, 2, 1},
	// {1, 2, 0},
	// {1, 0, 2},
	// {2, 0, 1},
	// {2, 1, 0},
	// };

	// unsigned int	identifiers[6] = {0};

	// int	i = 0;
	// while (i < 6)
	// {
	// 	identifiers[i] = make_hash(cases[i]);
	// 	i++;
	// }

	int i = 0;
	while (i < 6)
	
	{
		if (identifier == ids[i].identifier)
			return (ids[i].answer);
		i++;
	}
	return ("");
}

#include <stdio.h>
int	main()
{
	print_bits(0x00010200);
	int rank[3] = {0, 1, 2};
	printf("%s", solve_three(make_hash(rank)));
}