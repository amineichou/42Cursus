/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:44:27 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:42:01 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_get_last_node(t_stack_node *stack)
{
	t_stack_node	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

t_stack_node	*ft_get_prev_node(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*last;

	last = head;
	current = head;
	while (last->next)
	{
		current = last;
		last = last->next;
	}
	return (current);
}

t_stack_node	*ft_get_smallest_value(t_stack_node *head)
{
	t_stack_node	*smallest;

	smallest = head;
	while (head)
	{
		if (smallest->value > head->value)
			smallest = head;
		head = head->next;
	}
	return (smallest);
}

t_stack_node	*ft_get_biggest_value(t_stack_node *head)
{
	t_stack_node	*biggest;

	biggest = head;
	while (head)
	{
		if (biggest->value < head->value)
			biggest = head;
		head = head->next;
	}
	return (biggest);
}

t_stack_node	*ft_get_lowest_coast(t_stack_node *stack)
{
	t_stack_node	*node_lowest_coast;
	long			lowest_coast;

	lowest_coast = LONG_MAX;
	node_lowest_coast = NULL;
	while (stack)
	{
		if (lowest_coast > stack->coast)
		{
			lowest_coast = stack->coast;
			node_lowest_coast = stack ;
		}
		stack = stack->next;
	}
	return (node_lowest_coast);
}
