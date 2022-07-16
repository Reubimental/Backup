/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:42:41 by rkabzins          #+#    #+#             */
/*   Updated: 2022/05/19 19:42:51 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	<limits.h>
#include	<stdbool.h>
#include	"libft/libft.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
}

int	n_exists(unsigned int *stack, int stack_size, unsigned int check)
{
	int	index;

	index = 0;
	while (index < stack_size)
	{
		if (stack[index] == check)
			return (1);
		index++;
	}
	return (0);
}
unsigned int	*error_check(int argc, char **argv)
{
	int		index;
	int		i;
	char	digit;
	char	next_digit;
	unsigned int		*stack;
	long	n;

	index = 0;
	stack = malloc(sizeof(unsigned int) * (argc));
	if (argc == 0)
	{
		error_exit();
		return (0);
	}
	while (index < argc)
	{
		i = 0;
		digit = argv[index + 1][i];
		while (digit)
		{
			next_digit = argv[index + 1][i + 1];
			if (!(ft_isdigit(digit) || (digit == '-' && ft_isdigit(next_digit))))
			{
				error_exit();
				return (0);
			}
			i++;
			digit = argv[index + 1][i];
		}
		n = ft_atol(argv[index + 1]);
		if (n_exists(stack, index, n) == 1)
		{
			error_exit();
			return (0);
		}
		if (n < INT_MIN || n > INT_MAX)
		{
			error_exit();
			return (0);
		}
		stack[index] = n + INT_MAX + 1;
		index++;
	}
	return (stack);
}
void	ps_debug(unsigned int *stack_a, unsigned int *stack_b, int a_size, int b_size)
{
	int	index;

	index = 0;
	while (index < a_size)
		printf("a: %d\n", (stack_a[index++] - INT_MAX - 1));
	index = 0;
	while (index < b_size)
		printf("        b: %d\n", stack_b[index++] - INT_MAX - 1);
}

int	main(int argc, char **argv)
{
	unsigned int	*stack;
	unsigned int	*temp;
	int				size;

	size = argc - 1;
	stack = error_check(size, argv);
	temp = malloc(sizeof(int *) * size);
	if (stack == 0)
		return (EXIT_FAILURE);
	free(stack);
	free(temp);
	return (0);
}

/*

WHAT IS NEEDED:

1) Have a 'stack' entered and parsed for errors.
2) Populate Stack A with members from the input Stack.
3) Convert all members to Binary.
4) Use bitwise operations and the program commands to transfer any members of Stack A to Stack B that end in the bit '0'.
5) Transfer everything back to Stack A.
6) Bit shift once to the right.
7) Repeat 4-6 until everything is sorted.

*/
