/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:00:43 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/12 10:16:50 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	current_char;

	(void)context;
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
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s;

	s.sa_sigaction = &signal_handler;
	s.sa_flags = SA_SIGINFO;
	sigemptyset(&s.sa_mask);
	ft_printf("\e[1;92mMINITALK\n");
	ft_printf("\e[0;36mPID : %d\n\e[0m", getpid());
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
	return (0);
}
