/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:39:35 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/07 23:32:46 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H
# include <string.h>
# include "../libft/libft.h"

/*
 * server functions
 */

void	signal_rec(int code);
void	set_signals(void);
int		launch_server(void);
int		main(int ac, char **av);

/*
 *  client functions
 */

int		signal_error(void);
int		send_msg(int pid, char m);
int		launch_minitalk(char *av, char *msg);
void	sig(int sig);
int		main(int ac, char **av);

#endif
