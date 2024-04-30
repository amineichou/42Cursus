/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:28:17 by moichou           #+#    #+#             */
/*   Updated: 2024/02/25 15:13:07 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack_node *head)
{
	t_stack_node	*to_free_node;

	to_free_node = head;
	while (to_free_node)
	{
		free(to_free_node);
		to_free_node = to_free_node->next;
	}
	head = NULL;
}
