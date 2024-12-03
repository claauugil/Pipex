/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 09:01:22 by cgil              #+#    #+#             */
/*   Updated: 2024-11-26 09:01:22 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>

void	prep_pipe(int in_file, int out_file);
void	fork_error(void);
void	close_fds(int fd1, int fd2, int fd3, int fd4);
void	handle_first_child(int in_file, int *pipe_fds, char *env[], char *bin);
void	handle_sec_child(int out_file, int *pipe_fds, char *env[], char *bin);
char	**get_path(char **env);
void	exec(char *cmd, char *env[]);
char	*get_exec(char *cmd, char **paths);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
