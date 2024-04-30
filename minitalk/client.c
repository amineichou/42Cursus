/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:13:26 by moichou           #+#    #+#             */
/*   Updated: 2024/02/06 15:57:11 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_byte(pid_t pid, char byte)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (byte >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_puterror("Error : couldn't send signal to this process\n");
		}
		else if (bit == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_puterror("Error : couldn't send signal to this process\n");
		}
		usleep(420);
		i--;
	}
}

static void	send_msg(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		ft_send_byte(pid, msg[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			ft_puterror("Bad pid\n");
		if (ft_strlen(av[2]) == 0)
			ft_puterror("Error, empty string\n");
		send_msg(pid, av[2]);
	}
	else
		ft_puterror("Error : no valid args\n");
	return (0);
}
