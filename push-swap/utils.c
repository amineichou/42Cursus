/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:43:17 by moichou           #+#    #+#             */
/*   Updated: 2024/02/27 15:24:18 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack_node *stack)
{
	t_stack_node	*last;
	int				i;

	i = 0;
	if (!stack)
		return (0);
	last = stack;
	while (last)
	{
		last = last->next;
		i++;
	}
	return (i);
}

int	check_sorted(t_stack_node *stack)
{
	t_stack_node	*head;
	int				is_sorted;

	head = stack;
	is_sorted = 1;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_puterror(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

char	*ft_strsjoin(char **str, int ac)
{
	char	*result;
	int		size;
	int		i;
	int		x;

	i = 1;
	size = 0;
	while (i < ac)
		size += ft_strlen(str[i++]);
	result = malloc(sizeof(char) * (size + ac));
	if (!result)
		exit(0);
	i = 1;
	x = 0;
	while (i < ac)
	{
		size = 0;
		while (str[i][size])
			result[x++] = str[i][size++];
		result[x] = ' ';
		x++;
		i++;
	}
	result[x] = '\0';
	return (result);
}
