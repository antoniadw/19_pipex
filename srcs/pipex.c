/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:29:16 by ade-woel          #+#    #+#             */
/*   Updated: 2025/02/04 16:53:29 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

static void	exec_child1(t_args *args)
{
	int		fd_in;

	fd_in = open(args->av[1], O_RDWR);
	dup2(fd_in, 0);
	close(fd_in);
	dup2(args->fds[1], 1);
	close(args->fds[0]);
	args->path_cmd1 = find_cmd_path(args, args->cmd1[0]);
	if (execve(args->path_cmd1, args->cmd1, args->env) == -1)
	{
		ft_dprintf(2, "Command not found\n");
		close(args->fds[1]);
		free_tabs(args);
		free(args->path_cmd1);
		exit(1);
	}
}

static void	exec_child2(t_args *args)
{
	int	fd_out;

	fd_out = open(args->av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(fd_out, 1);
	close(fd_out);
	dup2(args->fds[0], 0);
	close(args->fds[1]);
	args->path_cmd2 = find_cmd_path(args, args->cmd2[0]);
	if (execve(args->path_cmd2, args->cmd2, args->env) == -1)
	{
		ft_dprintf(2, "Command not found\n");
		close(args->fds[0]);
		free_tabs(args);
		free(args->path_cmd2);
		exit(1);
	}
}

static void	init_processes(t_args *args)
{
	pid_t	pid;
	pid_t	pid2;

	pid = fork();
	if (pid < 0)
	{
		free_tabs(args);
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		exec_child1(args);
	pid2 = fork();
	if (pid2 < 0)
	{
		free_tabs(args);
		perror("fork");
		exit(1);
	}
	if (pid2 == 0)
		exec_child2(args);
	close(args->fds[0]);
	close(args->fds[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	t_args	args;

	verif_args(ac, av);
	args = (t_args){0};
	if (pipe(args.fds) == -1)
	{
		perror("pipe");
		exit(1);
	}
	args.ac = ac;
	args.av = av;
	args.env = env;
	init_paths(&args);
	init_processes(&args);
	free_all(&args);
	return (0);
}
