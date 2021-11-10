#include "../main.h"

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


t_cmd	get_cmd(t_list lst, char *argv_x, char **env)
{
	char		**cmd;
	char		*real_path;
	t_cmd		to_return;

	cmd = ft_split(argv_x, " ");
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
	to_return.cmd = real_path;
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