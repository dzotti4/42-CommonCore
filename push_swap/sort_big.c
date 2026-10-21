/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:10:57 by dzotti            #+#    #+#             */
/*   Updated: 2025/07/04 12:10:57 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// wijs elke node een index toe, kleinste krijgt 0, ++
void	assign_indexes(t_node *stack)
{
	int		index;
	t_node	*current;
	t_node	*compare;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

// bereken hoeveel bits nodig zijn voor max index, binair uit te drukken
static int	get_max_bits(t_node *stack)
{
	int	max;
	int	bits;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

// sorteer de stack door bit-per-bit te verglijken met radix sort
void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = stack_size(*a);
	bits = get_max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				write_pb(a, b);
			else
				write_ra(a);
			j++;
		}
		while (*b)
			write_pa(a, b);
		i++;
	}
}
