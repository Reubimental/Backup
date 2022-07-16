#include "libft/libft.h"

int	stack_size(unsigned int *stack)
{
	int size;

	size = 0;
	while (stack[size])	
		size++;
	return (size);
}

int	split_stack(unsigned int *stack_a, unsigned int *stack_b, unsigned int stack_size)
{
	int	BITMASK;
	int	index;

	index = 0;
	BITMASK = 0b1;
	while (stack[index] && stack_size)
	{
		if (stack[index] | BITMASK)
			ra(stack_a, 1);
		else
			pb(stack_a, 1);
	}

}


/*void sort_stack(unsigned int *stack)
{

}

void sort_stack_a()
{

}

*/
