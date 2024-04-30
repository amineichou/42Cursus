/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:32:15 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:41:58 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_cheapest_target_on_top(t_stack_node **stack_a,
			t_stack_node *cheapest)
{
	int	rotate_steps;

	if (cheapest->is_above_middle)
		rotate_steps = cheapest->index;
	else
		rotate_steps = ft_stack_size(*stack_a) - cheapest->index;
	while (rotate_steps)
	{
		if (cheapest->is_above_middle)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		rotate_steps--;
	}
}

static void	put_cheapest_on_top(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;
	int				rotate_steps;

	cheapest = ft_get_lowest_coast(*stack_b);
	if (cheapest->is_above_middle)
		rotate_steps = cheapest->index;
	else
		rotate_steps = ft_stack_size(*stack_b) - cheapest->index;
	while (rotate_steps)
	{
		if (cheapest->is_above_middle)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
		rotate_steps--;
	}
	put_cheapest_target_on_top(stack_a, cheapest->target_node);
}

static void	put_above_mid_on_top(t_stack_node **stack_a, t_stack_node **stack_b,
						t_stack_node *cheapest, int rotate_steps)
{
	while (cheapest != *stack_b && cheapest->target_node != *stack_a)
	{
		rotate_a_b(stack_a, stack_b);
		rotate_steps--;
	}
	while (cheapest->target_node != *stack_a && rotate_steps)
		rotate_a(stack_a);
	while (cheapest != *stack_b && rotate_steps)
		rotate_b(stack_b);
}

static void	put_none_above_mid_on_top(t_stack_node **stack_a,
			t_stack_node **stack_b, t_stack_node *cheapest, int rotate_steps)
{
	while (cheapest != *stack_b && cheapest->target_node != *stack_a)
	{
		reverse_rotate_a_b(stack_a, stack_b);
		rotate_steps--;
	}
	while (rotate_steps-- && cheapest->target_node != *stack_a)
		reverse_rotate_a(stack_a);
	while (rotate_steps-- && cheapest != *stack_b)
		reverse_rotate_b(stack_b);
}

void	choose_on_top(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;
	int				rotate_steps;

	cheapest = ft_get_lowest_coast(*stack_b);
	if (cheapest->is_above_middle && cheapest->target_node->is_above_middle)
	{
		rotate_steps = cheapest->index + cheapest->target_node->index;
		put_above_mid_on_top(stack_a, stack_b, cheapest, rotate_steps);
	}
	else if (!(cheapest->is_above_middle)
		&& !(cheapest->target_node->is_above_middle))
	{
		rotate_steps = (ft_stack_size(*stack_b) - cheapest->index)
			+ (ft_stack_size(*stack_a) - cheapest->target_node->index);
		put_none_above_mid_on_top(stack_a, stack_b, cheapest, rotate_steps);
	}
	else
		put_cheapest_on_top(stack_a, stack_b);
}
