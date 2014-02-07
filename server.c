/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:41:36 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/07 23:40:20 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

void		signal_rec(int	code)
{
	static char		c;
	static int		i;

	if (code == SIGUSR1)
		c += (1 << i);
	i++;
	if (i > 7)
	{
		if (!c)
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

void		set_signals(void)
{
	sleep(1);
	signal(SIGUSR1, signal_rec);
	signal(SIGUSR2, signal_rec);
}

int			launch_server(void)
{
	ft_putstr("PID = ");
	if (getpid() == 0)
		return (0);
	ft_putnbr(getpid());
	ft_putchar('\n');
	return (1);
}

int			main(int ac, char **av)
{
	if (ac != 1)
		return (0);
	if (launch_server() == 0)
		return (0);
	set_signals();
	(void)av;
	while (1)
		pause();
}
