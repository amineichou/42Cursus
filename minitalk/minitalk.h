/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:12:00 by moichou           #+#    #+#             */
/*   Updated: 2024/02/06 19:11:17 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_puterror(char *str);
int		ft_strlen(char *str);
void	ft_print_logo(pid_t pid);

#endif