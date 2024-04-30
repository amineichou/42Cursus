/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:58:03 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:41:44 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function append a node to a stack
static void	append_node_to_stack(t_stack_node **stack_head, t_stack_node *node)
{
	t_stack_node	*curr_node;

	curr_node = (*stack_head);
	while ((*stack_head)->next)
		(*stack_head) = (*stack_head)->next;
	(*stack_head)->next = node;
	node->next = NULL;
	(*stack_head) = curr_node;
}

static t_stack_node	*create_node(char *value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = ft_atoi(value);
	new_node->target_node = NULL;
	return (new_node);
}

// this function creates the stack form the splited str
t_stack_node	*set_stack(char **splited)
{
	t_stack_node	*stack_head;
	t_stack_node	*first_node;
	t_stack_node	*temp;
	int				i;

	first_node = create_node(splited[0]);
	first_node->next = NULL;
	stack_head = first_node;
	i = 1;
	while (splited[i])
	{
		temp = create_node(splited[i]);
		if (!temp)
		{
			free_stack(stack_head);
			exit(1);
		}
		append_node_to_stack(&stack_head, temp);
		i++;
	}
	return (stack_head);
}
