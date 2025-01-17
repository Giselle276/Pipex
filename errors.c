/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-26 13:00:13 by gmaccha-          #+#    #+#             */
/*   Updated: 2024-12-26 13:00:13 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_error(int fin_fd, char *argv)
{
	if (fin_fd < 0)
	{
		print_error(argv);
		fin_fd = open("/dev/null", O_RDONLY);
		if (fin_fd < 0)
		{
			perror("pipex: failed to open /dev/null");
			exit(EXIT_FAILURE);
		}
	}
}

void	fork_error(void)
{
	perror("Fork failed");
	exit(EXIT_FAILURE);
}

void	print_error(char *argv)
{
	if (access(argv, F_OK) == 0)
	{
		if (access(argv, R_OK) != 0)
		{
			ft_putstr("zsh: permission denied: ");
			ft_putstr(argv);
			ft_putstr("\n");
			return ;
		}
	}
	ft_putstr("zsh: no such file or directory: ");
	ft_putstr(argv);
	ft_putstr("\n");
}
