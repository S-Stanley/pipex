/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:45:37 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:45:38 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*get_shell(char **env)
{
	char	**shell;
	char	**tmp;
	char	*to_return;

	shell = get_var_path_env(env, "SHELL");
	if (!shell)
		return (ft_strdup(""));
	tmp = ft_split(shell[0], '/');
	free_that_matrice(shell);
	to_return = ft_strdup(tmp[count_len_array(tmp) - 1]);
	free_that_matrice(tmp);
	return (to_return);
}

t_list	get_infile(t_list lst, char **argv)
{
	int		fd;
	char	*shell;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		shell = get_shell(lst.env);
		str_write(shell);
		free(shell);
		str_write(": no such file or directory: ");
		str_write(argv[1]);
		free_lst(lst);
		exit(0);
	}
	close(fd);
	lst.infile = argv[1];
	return (lst);
}

t_list	get_outfile(t_list lst, char **argv)
{
	int		fd;
	char	*shell;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		close(fd);
		shell = get_shell(lst.env);
		str_write(shell);
		free(shell);
		str_write(": no such file or directory: ");
		str_write(argv[4]);
		free_lst(lst);
		exit(1);
	}
	close(fd);
	lst.outfile = argv[4];
	return (lst);
}
