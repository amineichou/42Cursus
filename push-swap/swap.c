/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:34:13 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:42:09 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap_stack the first two values on a stack
void	swap_stack(t_stack_node **stack)
{
	t_stack_node	*x;
	t_stack_node	*y;

	x = *stack;
	y = (*stack)->next;
	x->next = y->next;
	y->next = x;
	*stack = y;
}

void	swap_stack_a(t_stack_node **stack)
{
	int	size;

	size = ft_stack_size(*stack);
	if (size <= 1)
		return ;
	swap_stack(stack);
	ft_putstr("sa\n");
}

void	swap_stack_b(t_stack_node **stack)
{
	int	size;

	size = ft_stack_size(*stack);
	if (size <= 1)
		return ;
	swap_stack(stack);
	ft_putstr("sb\n");
}

void	swap_stack_a_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(*stack_a);
	size_b = ft_stack_size(*stack_b);
	if (size_a <= 1 || size_b <= 1)
		return ;
	swap_stack(stack_b);
	swap_stack(stack_a);
	ft_putstr("ss\n");
}
