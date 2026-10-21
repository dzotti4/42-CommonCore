/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:37:51 by dzotti            #+#    #+#             */
/*   Updated: 2025/06/27 21:37:51 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	write_pa(t_node **a, t_node **b)
{
	pa(a, b);
	write(1, "pa\n", 3);
}

void	write_pb(t_node **a, t_node **b)
{
	pb(a, b);
	write(1, "pb\n", 3);
}
