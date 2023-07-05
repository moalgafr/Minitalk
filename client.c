/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:27:21 by moalgafr          #+#    #+#             */
/*   Updated: 2023/06/16 17:55:33 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (((c >> i) & 1) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep (1000);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			write(1, "Error\n", 28);
			return (0);
		}
		while (argv[2][i] != '\0')
			sender(pid, argv[2][i++]);
		sender(pid, '\n');
	}
	else
	{
		write (1, "Error: Wrong Format\n", 20);
		return (1);
	}
	return (0);
}
