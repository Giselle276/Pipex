/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-26 13:00:08 by gmaccha-          #+#    #+#             */
/*   Updated: 2024-12-26 13:00:08 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

void	handle_first_child(int in_file, int *pipe_fds, char *env[], char *cmd);
void	handle_sec_child(int out_file, int *pipe_fds, char *env[], char *cmd);
void	ft_putstr(char *str);
void	file_error(int file_fd, char *argv);
void	fork_error(void);
void	print_error(char *argv);
void	prep_pipe(int in_file, int out_file);
void	pip_exec(char *cmd, char *env[]);
char	**get_path(char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_exec(char *cmd, char **paths);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
void	close_fds(int fd1, int fd2, int fd3, int fd4);

#endif
