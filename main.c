/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:09:46 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/10 14:43:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_argc(int argc)
{
	if (argc != 5)
	{
		str_write("Wrong number of arguments\n");
		exit(0);
	}
}

t_list	get_infile(t_list lst, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		str_write("No such file or directory");
		exit(1);
	}
	close(fd);
	lst.infile = argv[1];
	return (lst);
}

t_list	get_outfile(t_list lst, char **argv)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		close(fd);
		str_write("No such file or directory");
		exit(1);
	}
	close(fd);
	lst.outfile = argv[4];
	return (lst);
}

int	main(int argc, char **argv, char **env)
{
	t_list	lst;

	check_argc(argc);
	lst = get_infile(lst, argv);
	lst = get_outfile(lst, argv);
	//lst = get_cmd_1(argv, env);
	//lst = get_cmd_2(argv, env);	
	return (0);
}
