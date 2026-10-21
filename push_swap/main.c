/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:46:22 by dzotti            #+#    #+#             */
/*   Updated: 2025/06/25 19:46:22 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	run_sort(t_node **a, t_node **b)
{
	int	size;

	assign_indexes(*a);
	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			write_sa(a);
		return (0);
	}
	if (size == 3)
		return (sort_three(a), 0);
	if (size == 4 || size == 5)
		return (sort_five(a, b), 0);
	radix_sort(a, b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!split_arg(argv[1], &stack_a))
			return (free_stack(&stack_a), print_error());
	}
	else
	{
		if (!parse_arg(argv + 1, &stack_a))
			return (free_stack(&stack_a), print_error());
	}
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	run_sort(&stack_a, &stack_b);
	return (free_stack(&stack_a), 0);
}
