/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:44:12 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:41:32 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rotate_a(t_stack_node **stack)
{
	reverse_rotate(stack);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack_node **stack)
{
	reverse_rotate(stack);
	ft_putstr("rrb\n");
}

void	reverse_rotate_a_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
