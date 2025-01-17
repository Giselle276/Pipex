/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:36:57 by gmaccha-          #+#    #+#             */
/*   Updated: 2024/12/26 13:37:06 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_first_child(int in_file, int *pipe_fds, char *env[], char *cmd)
{
	prep_pipe (in_file, pipe_fds[1]);
	close_fds (in_file, pipe_fds[0], pipe_fds[1], 0);
	pip_exec (cmd, env);
	perror ("zsh: command not found");
	exit (EXIT_FAILURE);
}

void	handle_sec_child(int out_file, int *pipe_fds, char *env[], char *cmd)
{
	prep_pipe (pipe_fds[0], out_file);
	close_fds (out_file, pipe_fds[0], pipe_fds[1], 0);
	pip_exec(cmd, env);
	perror("zsh: command not found");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *env[])
{
	int		pipe_fds[2];
	int		fin_fd;
	int		fout_fd;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (write(2, "Run as: $> < file1 cmd1 | cmd2 > file2\n", 39), 1);
	pipe(pipe_fds);
	fin_fd = open(argv[1], O_RDONLY);
	file_error (fin_fd, argv[1]);
	fout_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pid1 = fork();
	if (pid1 == -1)
		fork_error();
	else if (pid1 == 0)
		handle_first_child(fin_fd, pipe_fds, env, argv[2]);
	pid2 = fork();
	if (pid2 == -1)
		fork_error();
	else if (pid2 == 0)
		handle_sec_child(fout_fd, pipe_fds, env, argv[3]);
	close_fds (fin_fd, fout_fd, pipe_fds[0], pipe_fds[1]);
	return (waitpid(pid1, NULL, 0), waitpid(pid2, NULL, 0), 0);
}
