/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:50:42 by moichou           #+#    #+#             */
/*   Updated: 2024/02/24 13:44:47 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					coast;
	int					is_above_middle;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

// extr funcs
t_stack_node	*set_stack(char **splited);
char			**ft_split(char *s, char c);

// utils
char			*ft_strsjoin(char **str, int ac);
void			ft_puterror(void);
int				check_sorted(t_stack_node *stack);
int				ft_stack_size(t_stack_node *stack);

// libft
size_t			ft_strlen(const char *str);
void			ft_putstr(char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_isspace(char c);

// stack getters
t_stack_node	*ft_get_last_node(t_stack_node *stack);
t_stack_node	*ft_get_prev_node(t_stack_node *head);
t_stack_node	*ft_get_smallest_value(t_stack_node *head);
t_stack_node	*ft_get_biggest_value(t_stack_node *head);
t_stack_node	*ft_get_lowest_coast(t_stack_node *stack);

// magic sort => hard coded sorting three nodes
void			sort_three(t_stack_node **stack);

// sort tools
void			choose_on_top(t_stack_node **stack_a, t_stack_node **stack_b);

// stack updater
void			set_cost(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_target_node(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_position_middle(t_stack_node *stack_a,
					t_stack_node *stack_b);
void			set_index(t_stack_node *stack);
void			update_stack(t_stack_node **stack_a, t_stack_node **stack_b);

// swap
void			swap_stack_a(t_stack_node **stack);
void			swap_stack_b(t_stack_node **stack);
void			swap_stack_a_b(t_stack_node **stack_a, t_stack_node **stack_b);

// rotate
void			rotate_a(t_stack_node **stack);
void			rotate_b(t_stack_node **stack);
void			rotate_a_b(t_stack_node **stack_a, t_stack_node **stack_b);

// reverse rotate
void			reverse_rotate_a(t_stack_node **stack);
void			reverse_rotate_b(t_stack_node **stack);
void			reverse_rotate_a_b(t_stack_node **stack_a,
					t_stack_node **stack_b);

// push
void			push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b);

// sorting algorithm
void			sort_stack(t_stack_node **stack_a, t_stack_node **stack_b);

// free leaks
void			free_double_str(char **str);
void			free_stack(t_stack_node *head);

#endif