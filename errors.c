/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-04 17:22:25 by cgil              #+#    #+#             */
/*   Updated: 2024-12-04 17:22:25 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_error(void)
{
	perror("Fork failed");
	exit(EXIT_FAILURE);
}

void	print_error(char *av)
{
	if (access(av, F_OK) == 0)
	{
		if (access(av, R_OK) != 0)
		{
			ft_putstr("zsh: permission denied: ");
			ft_putstr(av);
			exit(EXIT_FAILURE);
		}
	}
	ft_putstr("Error while opening : ");
	ft_putstr(av);
	exit(EXIT_FAILURE);
}
