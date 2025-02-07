/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:30:58 by ade-woel          #+#    #+#             */
/*   Updated: 2025/02/04 15:22:51 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*find_cmd_path(t_args *args, char *cmd)
{
	int		i;
	char	*path_cmd;
	char	*buffer;

	i = 0;
	buffer = NULL;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	while (args->paths[i])
	{
		buffer = ft_strjoin(args->paths[i], "/");
		path_cmd = ft_strjoin(buffer, cmd);
		free(buffer);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	return (NULL);
}

static char	**full_paths(char **env)
{
	char	*path;
	char	**tab_paths;

	tab_paths = NULL;
	if (env[0] == NULL)
	{
		ft_dprintf(2, "Could not find env\n");
		exit (1);
	}
	while (*env)
	{
		path = ft_strnstr(*env, "PATH=", 5);
		if (path)
		{
			path = ft_strtrim(path, "PATH=");
			tab_paths = ft_split(path, ':');
			break ;
		}
		env++;
	}
	free(path);
	return (tab_paths);
}

void	init_paths(t_args *args)
{
	args->paths = full_paths(args->env);
	if (args->paths == NULL)
	{
		perror("Paths");
		exit (1);
	}
	args->cmd1 = ft_split(args->av[2], ' ');
	if (!args->cmd1 || !args->cmd1[0])
	{
		free_tab(args->paths);
		free_tab(args->cmd1);
		ft_dprintf(2, "Command not found\n");
		exit (1);
	}
	args->cmd2 = ft_split(args->av[3], ' ');
	if (!args->cmd2 || !args->cmd2[0])
	{
		free_tab(args->paths);
		free_tab(args->cmd1);
		free_tab(args->cmd2);
		ft_dprintf(2, "Command not found\n");
		exit (1);
	}
}
