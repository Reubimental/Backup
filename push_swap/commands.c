#include "libft/libft.h"

// returns all members of stack_b to stack_a
void	return_to_stack(unsigned int *stack_a, unsigned int *stack_b)
{
	unsigned int stack_size_a;
	unsigned int stack_size_b;
	unsigned int stack_size;
	int index;

	stack_size_a = stack_size(stack_a);
	stack_size_b = stack_size(stack_b);
	stack_size = stack_size_a + stack_size_b;
	index = -1;
	while (--stack_size >= stack_size_b)
		stack_a[stack_size] = stack_a[stack_size - stack_size_b];
	while (index < stack_size_b)
	{
		stack_a[index] = stack_b[index];
		index++;
	}
}
// pushes the destination down one, then takes the first element of origin and
// puts it on top of the destination, then shrinks the origin.
void	ft_push(unsigned int *origin, unsigned int *destination)
{
	int	index;
	int	origin_size;

	origin_size = stack_size(origin);
	index = stack_size(destination);
	if (origin_size == 0)
		return ;
	while (index > 0)
	{
		destination[index] = destination[index - 1];
		index--;
	}
	destination[0] = origin[0];
	rotate(origin);
	origin_size--;
	origin[origin_size] = '\0';
}
// push the first element of b to the top of a.
void	pa(unsigned int *stack_a, unsigned int *stack_b, int command)
{
	ft_push(stack_b, stack_a);
	if (command == 1)
		printf("pa\n");
}
// push the first element of a to the top of b.
void	pb(unsigned int *stack_a, unsigned int *stack_b, int command)
{
	ft_push(stack_a, stack_b);
	if (command == 1)
		printf("pb\n");
}
// swap the first two elements of only a
void	swap(unsigned int *stack)
{
	int	size;
	int	temp;
	
	size = stack_size(stack);
	if (size < 2)
		return ;
	temp = stack[1];
	stack[1] = stack[0];
	stack[0] = temp;
}

// swap the first two elements of only a
void	sa(unsigned int *stack_a, int command)
{
	swap(stack_a);
	if (command == 1)
		printf("sa\n");
}

// swap the first two elements of only b
void	sb(unsigned int *stack_b, int command)
{
	swap(stack_b);
	if (command == 1)
		printf("sb\n");
}

// do sa and sb at the same time.
void	ss(unsigned int *stack_a, unsigned int *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	printf("ss\n");
}
// rotates the stack up by 1. First element becomes last.
void	rotate(unsigned int *stack)
{
	int	index;
	int	size;
	int	temp;

	size = (stack_size(stack));
	index = 0;
	temp = stack[0];
	while (index < size)
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[size - 1] = temp;
}
// shift all elements of stack a up by 1. First element becomes last.
void	ra(unsigned int *stack_a, int command)
{
	rotate(stack_a);
	if (command == 1)
		printf("ra\n");
}
// shift all elements of stack b up by 1. First element becomes last.
void	rb(unsigned int *stack_b, int command)
{
	rotate(stack_b);
	if (command == 1)
		printf("rb\n");
}
// do ra and rb at the same time.
void	rr(unsigned int *stack_a, unsigned int *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	printf("rr\n");
}
// rotates the stack down by 1. First element becomes last.
void	reverse_rotate(unsigned int *stack)
{
	int	index;
	int	temp;

	index = stack_size(stack);
	temp = stack[index - 1];
	while (--index)
		stack[index] = stack[index - 1];
	stack[0] = temp;
}
// shift all elements of stack a down by 1. last element becomes first.
void	rra(unsigned int *stack_a, int command)
{
	reverse_rotate(stack_a);
	if (command == 1)
		printf("rra\n");
}
// shift all elements of stack b down by 1. last element becomes first.
void	rrb(unsigned int *stack_b, int command)
{
	reverse_rotate(stack_b);
	if (command == 1)
		printf("rrb\n");
}
// do rra and rrb at the same time.
void	rrr(unsigned int *stack_a, unsigned int *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	printf("rrr\n");
}
