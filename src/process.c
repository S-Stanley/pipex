/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:02:56 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/10 19:05:02 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_lst(t_list lst)
{
	free_that_matrice(lst.arg1);
	free_that_matrice(lst.arg2);
	free(lst.cmd1);
	free(lst.cmd2);
}

void	parent_process(t_list lst)
{
	int	infile;

	infile = open(lst.infile, O_RDONLY);
	close(lst.fd[0]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(lst.fd[1], STDOUT_FILENO);
	if (execve(lst.cmd1, lst.arg1, lst.env))
	{
		free_lst(lst);
		exit(1);
	}
	close(lst.fd[1]);
}

void	child_process(t_list lst)
{
	int	fd;
	int	child_status;

	wait(&child_status);
	close(lst.fd[1]);
	if (access(lst.cmd2, X_OK) == -1)
	{
		str_write(lst.cmd2);
		str_write(" Cannot access this command");
		free_lst(lst);
		exit(1);
	}
	fd = open(lst.outfile, O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(lst.fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(lst.fd[0]);
	close(fd);
	execve(lst.cmd2, lst.arg2, lst.env);
}

void	pipex(t_list lst)
{
	int	fd;
	
	if (pipe(lst.fd) == -1)
	{
		str_write("Error starting pipe");
		exit(1);
	}
	lst.pid = fork();
	if (lst.pid == -1)
	{
		str_write("Error starting the fork");
		exit(1);
	}
	if (lst.pid == 0)
		parent_process(lst);
	else
	{
		fd = fork();
		if (fd == 0)
			child_process(lst);
	}
	free_lst(lst);
}
