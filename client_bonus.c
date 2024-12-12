/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:00:41 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/12 09:31:24 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(int pid, unsigned char character)
{
	int		i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(300);
	}
}

void handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received bit 1\n");
	else if (signal == SIGUSR2)
		ft_printf("Received bit 0\n");	
}

int main (int argc, char **argv)
{
	int			pid;
	int			i;
	const char	*message;

	i = 0;
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	if (argc != 3)
	{
		ft_printf("Erreur d'arguments (Format : PID ""'message'"")\n");
		exit (0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (message[i])
	{
		send_signal(pid, message[i]);
		i++;
	}
	send_signal(pid,'\0');
	return (0);
}