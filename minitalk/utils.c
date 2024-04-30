/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:15:31 by moichou           #+#    #+#             */
/*   Updated: 2024/02/06 20:36:06 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		result += str[i] - 48;
		i++;
	}
	return ((int)(result * sign));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
    char buffer[20]; // Assuming the maximum length of the integer is less than 20 characters
    int length = 0;

    // Convert the integer to a string
    do {
        buffer[length++] = '0' + n % 10;
        n /= 10;
    } while (n != 0);

    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }

    // Write the string to standard output
    write(1, buffer, length);
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
    ft_putstr("\033[0;31m");
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
    ft_putstr("\033[0m");
	exit (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// logo 
void	ft_print_logo(pid_t pid)
{
	ft_putstr("\n");
	ft_putstr("███    ███ ██ ███    ██ ██     ████████  █████  ██      ██   ██\n");
	usleep(100000);
	ft_putstr("████  ████ ██ ████   ██ ██        ██    ██   ██ ██      ██  ██\n");
	usleep(100000);
	ft_putstr("██ ████ ██ ██ ██ ██  ██ ██        ██    ███████ ██      █████\n");
	usleep(100000);
	ft_putstr("██  ██  ██ ██ ██  ██ ██ ██        ██    ██   ██ ██      ██  ██ \n");
	usleep(100000);
	ft_putstr("██      ██ ██ ██   ████ ██        ██    ██   ██ ███████ ██   ██\n\n");
    ft_putstr("\033[0;34mBy : Mohamed Amine ichou\n\n");
	ft_putstr("\033[0;31mPID : ");
	ft_putnbr(pid);
	ft_putstr("\033[0m\n\n");
}