/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:15:10 by ade-woel          #+#    #+#             */
/*   Updated: 2025/02/04 10:51:27 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_args
{
	char	**cmd1;
	char	**cmd2;
	char	**paths;
	char	*path_cmd1;
	char	*path_cmd2;
	int		fds[2];
	int		ac;
	char	**av;
	char	**env;
}	t_args;

char	*find_cmd_path(t_args *args, char *cmd);
void	free_all(t_args *args);
void	free_tab(char **tab);
void	free_tabs(t_args *args);
void	init_paths(t_args *args);
void	verif_args(int ac, char **av);

#endif