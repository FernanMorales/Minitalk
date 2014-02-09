/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:05:32 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/09 21:01:58 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

int			signal_error(void)
{
	ft_putendl("signal error. process aborted");
	return (0);
}

int			send_msg(int pid, char m)
{
	char	c;

	c = 0;
	while (c < 8)
	{
		if ((m >> c) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (signal_error());
			pause();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (signal_error());
			pause();
		}
		++c;
	}
	return (1);
}

int			launch_minitalk(char *av, char *msg)
{
	int		i;
	int		pid;

	pid = ft_atoi(av);
	i = -1;
	while (msg[++i])
	{
		if (send_msg(pid, msg[i]) == 0)
			return (0);
	}
	send_msg(pid, msg[i]);
	return (1);
}

void		sig(int signal)
{
	signal = (int)sig;
}

int			main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putendl("ENTER 2 PARAMETERS : PID AND MESSAGE");
		return (0);
	}
	if (signal(SIGUSR1, sig) == SIG_ERR || signal(SIGUSR2, sig) == SIG_ERR)
		return (signal_error());
	if (launch_minitalk(av[1], av[2]) == 0)
		return (0);
	return (0);
}
