/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:09:46 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/10 18:04:06 by ubuntu           ###   ########.fr       */
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

void	free_that_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}

char	*concat_path(char *s1, char *s2, char *s3)
{
	char	*str1;
	char	*str2;

	str1 = ft_concat(s1, s2);
	if (!str1)
		return (NULL);
	str2 = ft_concat(str1, s3);
	if (!str2)
	{
		free(str1);
		return (NULL);
	}
	free(str1);
	return (str2);
}

char	*whereis_cmd(char **cmd, char **env)
{
	char 		**path;
	unsigned int	x;
	char		*real_cmd;

	path = get_path_var(cmd, env);
	if (!path)
		return (NULL);
	x = 0;
	while (path[x])
	{
		real_cmd = concat_path(path[x], "/", cmd[0]);
		if (access(real_cmd, X_OK) == 0)
		{
			free_that_matrice(path);
			return (real_cmd);
		}
		free(real_cmd);
		x++;
	}
	free_that_matrice(path);
	return (NULL);
}

char	**get_path_var(char **cmd, char **env)
{
	char		**path;
	unsigned int	i;
	char		**str;

	i = 0;
	while (env[i])
	{
		if (count_occ(env[i], "PATH"))
		{
			str = ft_split(env[i], "=");
			path = ft_split(str[1], ":");
			free_that_matrice(str);
			return (path);
		}
		i++;
	}
	return (NULL);
}

t_list	get_cmd_1(t_list lst, char **argv, char **env)
{
	char	**cmd;
	char	*real_path;

	cmd = ft_split(argv[2], " ");
	if (!cmd || !cmd[0])
	{
		free_that_matrice(cmd);
		exit(0);
	}
	real_path = whereis_cmd(cmd, env);
	if (!real_path)
	{
		free_that_matrice(cmd);
		str_write("No path in env variable");
		exit(0);
	}
	free_that_matrice(cmd);
	return (lst);
}

int	main(int argc, char **argv, char **env)
{
	t_list	lst;

	check_argc(argc, env);
	lst = get_infile(lst, argv);
	lst = get_outfile(lst, argv);
	lst = get_cmd_1(lst, argv, env);
	//lst = get_cmd_2(lst, argv, env);	
	return (0);
}
