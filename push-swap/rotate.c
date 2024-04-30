/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:01:21 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:41:36 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*sec;

	last = ft_get_last_node(*stack);
	sec = (*stack)->next;
	last->next = *stack;
	last->next->next = NULL;
	*stack = sec;
}

void	rotate_a(t_stack_node **stack)
{
	int	size;

	size = ft_stack_size(*stack);
	if (size <= 1)
		return ;
	rotate(stack);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack_node **stack)
{
	int	size;

	size = ft_stack_size(*stack);
	if (size <= 1)
		return ;
	rotate(stack);
	ft_putstr("rb\n");
}

void	rotate_a_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(*stack_a);
	size_b = ft_stack_size(*stack_b);
	if (size_a <= 1 || size_b <= 1)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
