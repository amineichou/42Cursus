/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:05:12 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:41:24 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push top of a to b
void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	if (ft_stack_size(*stack_a) == 0)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_putstr("pb\n");
}

// push top of b to a
void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	if (ft_stack_size(*stack_b) == 0)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putstr("pa\n");
}
