/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:18:57 by moichou           #+#    #+#             */
/*   Updated: 2024/03/02 18:48:07 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doublcates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_for_empty_string(char **str, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isspace(str[i][j]))
				break ;
			j++;
		}
		if (str[i][j] == '\0')
			ft_puterror();
		i++;
	}
}

static int	check_foronly_numbers(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((!ft_isdigit(av[i][j]) && !ft_isspace(av[i][j])
				&& av[i][j] != '+' && av[i][j] != '-') || (av[i][j] == '\t'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_valid_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-')
				&& av[i][j + 1] && !ft_isdigit(av[i][j + 1]))
				return (-1);
			if ((av[i][j] == '+' || av[i][j] == '-') && !av[i][j + 1])
				return (-1);
			if (ft_isdigit(av[i][j]) && av[i][j + 1]
				&& !ft_isdigit(av[i][j + 1]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void gg(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	atexit(gg);
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (ac == 1)
		return (0);
	if (ac >= 2)
	{
		check_for_empty_string(av, ac);
		av = ft_split(ft_strsjoin(av, ac), ' ');
		if (check_valid_args(av) == -1 || !check_foronly_numbers(av)) 
		{
			free_double_str(av);
			ft_puterror();
		}
	}
	if (check_doublcates(av))
	{
		free_double_str(av);
		ft_puterror();
	}
	stack_a = set_stack(av);
	stack_b = NULL;
	if (!check_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	return (free_double_str(av), (free_stack(stack_a), 0));
}
