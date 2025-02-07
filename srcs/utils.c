/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:18:50 by ade-woel          #+#    #+#             */
/*   Updated: 2025/02/05 10:04:11 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	verif_args(int ac, char **av)
{
	int	fd;
	int	fd2;

	if (ac != 5)
	{
		ft_dprintf(2, "Error, arguments input is invalid.\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		fd2 = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		close(fd2);
		perror(av[1]);
		exit(1);
	}
	fd2 = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd2 < 0)
	{
		close(fd);
		perror(av[4]);
		exit(1);
	}
	close(fd);
	close(fd2);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(t_args *args)
{
	free_tab(args->paths);
	args->paths = NULL;
	free_tab(args->cmd1);
	args->cmd1 = NULL;
	free_tab(args->cmd2);
	args->cmd2 = NULL;
	free(args->path_cmd1);
	args->path_cmd1 = NULL;
	free(args->path_cmd2);
	args->path_cmd2 = NULL;
}

void	free_tabs(t_args *args)
{
	free_tab(args->paths);
	args->paths = NULL;
	free_tab(args->cmd1);
	args->cmd1 = NULL;
	free_tab(args->cmd2);
	args->cmd2 = NULL;
}
