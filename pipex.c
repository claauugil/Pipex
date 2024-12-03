/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 10:57:23 by cgil              #+#    #+#             */
/*   Updated: 2024/11/30 16:54:32 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_error(void)
{
	perror("Fork failed");
	exit(EXIT_FAILURE);
}

void	open_error(void)
{
	perror("Error opening file");
	exit(EXIT_FAILURE);
}

void	handle_first_child(int in_file, int *pipe_fds, char *env[], char *cmd)
{
	prep_pipe(in_file, pipe_fds[1]);
	close_fds(in_file, pipe_fds[0], pipe_fds[1], 0);
	exec(cmd, env);
	perror("Error executing command");
	exit(EXIT_FAILURE);
}

void	handle_sec_child(int out_file, int *pipe_fds, char *env[], char *cmd)
{
	prep_pipe(pipe_fds[0], out_file);
	close_fds(out_file, pipe_fds[0], pipe_fds[1], 0);
	exec(cmd, env);
	perror("Error executing command");
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[], char *env[])
{
	int		pipe_fds[2];
	int		fin_fd;
	int		fout_fd;
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		return (write(2, "Not enough arguments", 21), 1);
	pipe(pipe_fds);
	fin_fd = open(av[1], O_RDONLY);
	if (fin_fd < 0)
		open_error();
	fout_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pid1 = fork();
	if (pid1 == -1)
		fork_error();
	else if (pid1 == 0)
		handle_first_child(fin_fd, pipe_fds, env, av[2]);
	pid2 = fork();
	if (pid2 == -1)
		fork_error();
	else if (pid2 == 0)
		handle_sec_child(fout_fd, pipe_fds, env, av[3]);
	close_fds(fin_fd, fout_fd, pipe_fds[0], pipe_fds[1]);
}
