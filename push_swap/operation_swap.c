/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:04:37 by dzotti            #+#    #+#             */
/*   Updated: 2025/06/27 14:04:37 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	write_sa(t_node **a)
{
	sa(a);
	write(1, "sa\n", 3);
}

void	write_sb(t_node **b)
{
	sb(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
