/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:45:47 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:45:48 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_lst(t_list lst)
{
	free_that_matrice(lst.arg1);
	free_that_matrice(lst.arg2);
}

void	parent_process(t_list lst)
{
	int	infile;

	infile = open(lst.infile, O_RDONLY);
	close(lst.fd[0]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(lst.fd[1], STDOUT_FILENO);
	if (execve(lst.arg1[0], lst.arg1, lst.env))
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
	fd = open(lst.outfile, O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(lst.fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(lst.fd[0]);
	close(fd);
	if (execve(lst.arg2[0], lst.arg2, lst.env))
	{
		free_lst(lst);
		exit(1);
	}
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