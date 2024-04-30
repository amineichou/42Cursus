/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:07:44 by moichou           #+#    #+#             */
/*   Updated: 2024/02/26 21:45:58 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_step(t_stack_node **stack_a)
{
	t_stack_node	*smallest_node_value;
	int				rotate_steps;

	smallest_node_value = ft_get_smallest_value(*stack_a);
	if (smallest_node_value->is_above_middle)
		rotate_steps = smallest_node_value->index;
	else
		rotate_steps = ft_stack_size(*stack_a) - smallest_node_value->index;
	while (rotate_steps)
	{
		if (smallest_node_value->is_above_middle)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		rotate_steps--;
	}
}

static void	best_move(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	med;

	med = ((ft_get_biggest_value(*stack_a)->value / 2)
			+ (ft_get_smallest_value(*stack_a)->value / 2));
	while (ft_stack_size(*stack_a) > 3)
	{
		push_a_to_b(stack_a, stack_b);
		if ((*stack_b)->value >= med)
			rotate_b(stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		update_stack(stack_a, stack_b);
		choose_on_top(stack_a, stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	update_stack(stack_a, stack_b);
	final_step(stack_a);
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else
		best_move(stack_a, stack_b);
}
