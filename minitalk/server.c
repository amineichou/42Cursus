/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:13:43 by moichou           #+#    #+#             */
/*   Updated: 2024/02/06 20:23:59 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		count;
	static char		byte;
	int				bit;
	static pid_t	old_pid;

	bit = 0;
	if (old_pid == 0)
		old_pid = info->si_pid;
	if (old_pid != info->si_pid)
	{
		count = 0;
		byte = 0;
		old_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		bit = 1;
	byte = (byte << 1) | bit;
	count++;
	if (count == 8)
	{
		write(1, &byte, 1);
		count = 0;
		byte = 0;
	}
	(void)context; // not used
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_print_logo(pid); // print minitalk logo and process id
	action.sa_sigaction = &signal_handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_putstr("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_putstr("Failed to change SIGUSR2's behavior");
	while (1)
		pause();
	return (0);
}
