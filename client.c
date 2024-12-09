/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:21:56 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/09 10:51:41 by mpajot-t         ###   ########.fr       */
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
		usleep(42);
	}
}

int main (int argc, char **argv)
{
	int			pid;
	int			i;
	const char	*message;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Erreur d'arguments\n");
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
