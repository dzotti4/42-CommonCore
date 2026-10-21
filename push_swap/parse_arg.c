/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:02:59 by dzotti            #+#    #+#             */
/*   Updated: 2025/06/26 20:02:59 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// checkt als de waarde al in de stack zit
int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// verwerkt een lijst van strings (bv. "3", "4", "5")
int	parse_arg(char **argv, t_node **stack)
{
	int		i;
	int		value;
	t_node	*new;

	i = 0;
	while (argv[i])
	{
		if (!safe_atoi(argv[i], &value) || has_duplicate(*stack, value))
		{
			free_stack(stack);
			return (0);
		}
		new = create_node(value);
		if (!new)
		{
			free_stack(stack);
			return (0);
		}
		add_node_back(stack, new);
		i++;
	}
	return (1);
}

// verwerkt een string als "3 4 5", splits deze en vult de stack
int	split_arg(char *arg, t_node **stack)
{
	char	**split;
	int		result;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	result = parse_arg(split, stack);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (!result)
		return (0);
	return (1);
}
