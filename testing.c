/******************************************************************************

							Online C Compiler.
				Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
	const int  *srcstr;
	int        *deststr;
	
	srcstr = src;
	deststr = dest;
	while (n--)
		*deststr++ = *srcstr++;
	return (dest);
}

int	stack_size(unsigned int *stack)
{
	int size;

	size = 0;
	while (stack[size])	
		size++;
	return (size);
}

void	*return_to_stack(unsigned int *stack_a, unsigned int *stack_b)
{
	unsigned int stack_size_a;
	unsigned int stack_size_b;
	unsigned int stack_size_;
	int *output;

	stack_size_a = stack_size(stack_a);
	stack_size_b = stack_size(stack_b);
	stack_size_ = stack_size_a + stack_size_b;
	output = malloc(sizeof(int) * stack_size_);
//	ft_memcpy(output, stack_b, stack_size_b);
	while (stack_size_)
	{
		while (stack_size_b)
		{
			output++ = stack_b++;
			stack_size_b--;
			stack_size_--;
		}
		while (stack_size_a)
		{
			output++ = stack_a++;
			stack_size_a--;
			stack_size_--;
		}
	}
	return (output);
}

int main()
{
	int index = 0;
	int *stack_a = malloc(sizeof(int) * 10);
	int *stack_b = malloc(sizeof(int) * 4);
	
	stack_a[0] = 1;
	stack_a[1] = 4;
	stack_a[2] = 3;
	stack_a[3] = 7;
	stack_a[4] = 12;
	stack_a[5] = 9;
	stack_b[0] = 5;
	stack_b[1] = 8;
	stack_b[2] = 2;
	stack_b[3] = 0;
	printf("Stack A has numbers: ");
	while(index < 6)
	{
		printf("%d", stack_a[index]);
		if (index != 5)
			printf(", ");
		index++;
	}
	printf("\n");
	index = 0;
	printf("Stack B has numbers: ");
	while(index < 4)
	{
		printf("%d, ", stack_b[index]);
		index++;
	}
	printf("\n");
	printf("PERFORMING FULL STACK PUSH.....\n");
	stack_a = return_to_stack(stack_a, stack_b);
	index = 0;
	printf("Stack A has numbers: ");
	while(index < 10)
	{
		printf("%d", stack_a[index]);
		if (index != 9)
			printf(", ");
		index++;
	}
	printf("\n");
	index = 0;
	printf("Stack B has numbers: ");
	while(index < 4)
	{
		printf("%d, ", stack_b[index]);
		index++;
	}
	printf("\n");
	return 0;
}
