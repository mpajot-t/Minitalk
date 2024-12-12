/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:49:17 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/12 10:15:32 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int				bit;
	static unsigned char	current_char;

	if (signal == SIGUSR1)
		current_char |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit = 0;
		current_char = 0;
	}
}

int	main(void)
{
	ft_printf("\e[1;92mMINITALK\n");
	ft_printf("\e[0;36mPID : %d\n\e[0m", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
