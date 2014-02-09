/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:41:36 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/09 22:11:10 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

void					print_client(char **message, int *counter)
{
	int					i;

	i = *counter;
	(*message)[i] = '\0';
	ft_putendl(*message);
	free(*message);
	*counter = 0;
}

void					get_bit_1(int signal, siginfo_t *siginfo, void *context)
{
	static char			c;
	static int			i;
	static char			*message;
	static int			counter;

	(void)context;
	message = counter ? message : (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (signal == SIGUSR1)
		c += (1 << i);
	i++;
	if (i > 7)
	{
		if (!c)
			print_client(&message, &counter);
		else
		{
			message[counter] = c;
			++counter;
		}
		c = 0;
		i = 0;
	}
	usleep(30);
	kill(siginfo->si_pid, SIGUSR1);
}

int						launch_server(void)
{
	ft_putstr("PID = ");
	if (getpid() == 0)
		return (0);
	ft_putnbr(getpid());
	ft_putchar('\n');
	return (1);
}

int						main(int ac, char **av)
{
	struct sigaction    sighandler1;

	if (ac != 1)
		return (0);
	if (launch_server() == 0)
		return (0);
	sighandler1.sa_sigaction = get_bit_1;
	sighandler1.sa_flags = SA_SIGINFO;
	sighandler1.sa_flags |= SA_NODEFER;
	sigaction(SIGUSR1, &sighandler1, NULL);
	sigaction(SIGUSR2, &sighandler1, NULL);
	(void)av;
	while (1)
		pause();
}
