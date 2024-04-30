/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:26:15 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:40:59 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*biggest;

	if (check_sorted(*stack))
		return ;
	biggest = ft_get_biggest_value(*stack);
	if (biggest == (*stack))
		rotate_a(stack);
	else if (biggest == (*stack)->next)
		reverse_rotate_a(stack);
	if (!check_sorted(*stack))
		swap_stack_a(stack);
}
