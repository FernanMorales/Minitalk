/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 22:13:51 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/09 22:15:04 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H
# include <string.h>
# include <signal.h>
# include "../libft/libft.h"
# define BUFF_SIZE 1000000

/*
 * server functions
 */

void	get_bit_1(int signal, siginfo_t *, void *context);
int		launch_server(void);
int		main(int ac, char **av);
void	print_client(char **message, int *counter);

/*
 *  client functions
 */

int		signal_error(void);
int		send_msg(int pid, char m);
int		launch_minitalk(char *av, char *msg);
void	sig(int sig);
int		main(int ac, char **av);

#endif
