/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:11:29 by dzotti            #+#    #+#             */
/*   Updated: 2025/06/25 20:11:29 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// struct voor 1 node in stack
typedef struct s_node
{
	int				value;	// int die we sorteren
	int				index;
	struct s_node	*next;	// pointer naar de volgende node
}	t_node;

int		handle_space_sign(char *str, int *i, int *sign);
int		safe_atoi(char *str, int *result);

t_node	*create_node(int value);
void	add_node_back(t_node **stack, t_node *new);
int		parse_arg(char **argv, t_node **stack);
int		has_duplicate(t_node *stack, int value);
int		parse_split_arg(char *arg, t_node **stack);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
t_node	*last_node(t_node *stack);
int		is_sorted(t_node *stack);
int		split_arg(char *arg, t_node **stack);
// algo
void	sort_three(t_node **stack);
void	sort_five(t_node **a, t_node **b);
void	assign_indexes(t_node *stack);
void	radix_sort(t_node **a, t_node **b);
// lifbft
char	**ft_split(char const *s, char c);
// swap functies
void	sa(t_node **a);
void	sb(t_node **b);
void	write_sa(t_node **a);
void	write_sb(t_node **b);
void	ss(t_node **a, t_node **b);
// push functies
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	write_pb(t_node **a, t_node **b);
void	write_pa(t_node **a, t_node **b);
// rotate functies
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	write_ra(t_node **a);
void	write_rb(t_node **b);
// reverse rotate functies
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	write_rra(t_node **a);
void	write_rrb(t_node **b);

#endif
