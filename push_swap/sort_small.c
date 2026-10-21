/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:47:51 by dzotti            #+#    #+#             */
/*   Updated: 2025/07/03 12:47:51 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = *stack;
	b = a->next;
	c = b->next;
	if (a->value > b->value && b->value < c->value && a->value < c->value)
		write_sa(stack);
	else if (a->value > b->value && b->value > c->value)
	{
		write_sa(stack);
		write_rra(stack);
	}
	else if (a->value < b->value && b->value > c->value && a->value > c->value)
		write_rra(stack);
	else if (a->value > b->value && b->value < c->value && a->value > c->value)
		write_ra(stack);
	else if (a->value < b->value && b->value > c->value && a->value < c->value)
	{
		write_sa(stack);
		write_ra(stack);
	}
}

// zoekt laagste waarde in stack
static int	find_min(t_node *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

// zet kleinste getal bovenaan door te roteren
static void	move_smallest_to_top(t_node **stack)
{
	int		min;
	int		pos;
	int		size;
	t_node	*tmp;

	min = find_min(*stack);
	tmp = *stack;
	pos = 0;
	while (tmp && tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	size = stack_size(*stack);
	if ((*stack)->value == min)
		return ;
	if (pos <= size / 2)
		while ((*stack)->value != min)
			write_ra(stack);
	else
		while ((*stack)->value != min)
			write_rra(stack);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		move_smallest_to_top(a);
		write_pb(a, b);
	}
	sort_three(a);
	while (*b)
		write_pa(a, b);
}
