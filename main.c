/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:45:23 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:45:24 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_argc(int argc, char **env)
{
	if (argc != 5)
	{
		str_write("Wrong number of arguments\n");
		exit(0);
	}
	if (!env)
	{
		str_write("No environnement");
		exit(0);
	}
}

void	read_matrice(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		printf("-%s\n", arr[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	lst;
	t_cmd	parse;

	check_argc(argc, env);
	lst = get_infile(lst, argv);
	lst = get_outfile(lst, argv);
	parse = get_cmd(lst, argv[2], env);
	lst.cmd1 = parse.cmd;
	lst.arg1 = parse.arg;
	parse = get_cmd(lst, argv[3], env);
	lst.cmd2 = parse.cmd;
	lst.arg2 = parse.arg;
	lst.env = env;
	pipex(lst);
	return (0);
}
