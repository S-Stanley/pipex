/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:45:43 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:45:44 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**get_var_path_env(char **env, char *to_find)
{
	unsigned int	i;

	i = 0;
	while (env[i])
	{
		if (env[i])
		{
			if (start_with(env[i], to_find))
				return (ft_split(env[i], ':'));
		}
		i++;
	}
	return (NULL);
}

char	*whereis_cmd(char **cmd, char **env)
{
	char			**path;
	unsigned int	i;
	char			*concat;
	char			*tmp;
	char			*to_return;

	path = get_var_path_env(env, "PATH");
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin("/", cmd[0]);
		concat = ft_strjoin(path[i], tmp);
		free(tmp);
		if (access(concat, X_OK) == 0)
		{
			to_return = concat;
			free_that_matrice(path);
			return (to_return);
		}
		free(concat);
		i++;
	}
	free_that_matrice(path);
	return (NULL);
}

char	**get_arg(char **arr, char *real_path, char **cmd)
{
	unsigned int	i;

	i = 1;
	arr = NULL;
	arr = push_arr(arr, real_path);
	if (!arr)
		return (NULL);
	while (cmd[i])
	{
		arr = push_arr(arr, cmd[i]);
		if (!arr)
		{
			free_that_matrice(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

t_cmd	get_cmd(char *argv_x, t_list lst, int code_error)
{
	char		**cmd;
	char		*real_path;
	t_cmd		to_return;

	cmd = ft_split(argv_x, ' ');
	if (!cmd || !cmd[0])
	{
		free_that_matrice(cmd);
		exit(0);
	}
	real_path = whereis_cmd(cmd, lst.env);
	to_return.cmd = real_path;
	if (is_path_ok(real_path, cmd, lst, argv_x))
		exit(code_error);
	to_return.arg = get_arg(to_return.arg, real_path, cmd);
	free(cmd[0]);
	free(cmd);
	if (!to_return.arg)
	{
		str_write("Error while allocating for get arguments 1");
		free(real_path);
		exit(0);
	}
	return (to_return);
}
