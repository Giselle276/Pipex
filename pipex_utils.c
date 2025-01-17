/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 12:11:01 by gmaccha-          #+#    #+#             */
/*   Updated: 2024-12-27 12:11:01 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	prep_pipe(int in_file, int out_file)
{
	dup2(in_file, STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
}

void	pip_exec(char *cmd, char *env[])
{
	char	**paths;
	char	**args;

	paths = get_path(env);
	args = ft_split(cmd, ' ');
	args[0] = get_exec(args[0], paths);
	if (args[0] == NULL)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	execve(args[0], args, env);
	perror("pipex: execve failed");
	exit(EXIT_FAILURE);
}

char	**get_path(char **env)
{
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			break ;
		env++;
	}
	if (*env == NULL)
	{
		write(2, "ERROR: PATH variable not found\n", 32);
		exit(EXIT_FAILURE);
	}
	paths = ft_split(*env + 5, ':');
	return (paths);
}

char	*get_exec(char *cmd, char **paths)
{
	char	*path;

	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	return (NULL);
}

void	close_fds(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 > 0)
		close (fd1);
	if (fd2 > 0)
		close (fd2);
	if (fd3 > 0)
		close (fd3);
	if (fd4 > 0)
		close (fd4);
}
