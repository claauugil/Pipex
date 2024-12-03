/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 08:59:48 by cgil              #+#    #+#             */
/*   Updated: 2024-11-26 08:59:48 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	prep_pipe(int in_file, int out_file)
{
	dup2(in_file, STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
}

void	exec(char *cmd, char *env[])
{
	char	**args;
	char	**paths;

	paths = get_path(env);
	args = ft_split(cmd, ' ');
	args[0] = get_exec(args[0], paths);
	execve(args[0], args, env);
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
