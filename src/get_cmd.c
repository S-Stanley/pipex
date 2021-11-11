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

int		ft_count(const char *str, char c)
{
	int		i;
	int		count;
	int		size;

	i = 0;
	count = 0;
	size = (int)ft_strlen((char *)str);
	while (i < size && str[i])
	{
		while (i < size && str[i] != c)
			i++;
		count++;
		while (i < size && str[i] == c)
			i++;
	}
	return (count + 1);
}

char	*ft_new(char *str, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start != end)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_split_2(char *str, char c, int i)
{
	int start;

	start = i;
	while (str[i] != c && str[i])
		i++;
	return (ft_new(str, start, i));
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		x;
	char	**res;
	int		start;
	int		size;

	if (!str)
		return (NULL);
	if (!(res = malloc(sizeof(char *) * ft_count(str, c))))
		return (NULL);
	i = 0;
	x = -1;
	size = (int)ft_strlen((char *)str);
	while (i < size)
	{
		start = i;
		while (i < size && str[i] != c)
			i++;
		if (start != 0 || str[start] != c)
			res[++x] = ft_new((char *)str, start, i);
		while (i < size && str[i] == c)
			i++;
	}
	res[++x] = NULL;
	return (res);
}

void	ft_concat(const char *s1, const char *s2, char *res)
{
	int		i;
	int		n;

	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	n = i;
	i = 0;
	while (s2[i])
	{
		res[n] = s2[i];
		n++;
		i++;
	}
	res[n] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	ft_concat(s1, s2, res);
	return (res);
}

int     start_with(char *str, char *occurence)
{
        unsigned int    i;

        i = 0;
        while (occurence[i])
        {
                if (str[i] != occurence[i])
                        return (0);
                i++;
        }
        return (1);
}

char    **get_var_path_env(char **env, char *to_find)
{
        unsigned int    i;

        i = 0;
        while (env[i])
        {
                if (start_with(env[i], to_find))
                        return (ft_split(env[i], ':'));
                i++;
        }
        return (NULL);
}


char	*whereis_cmd(char **cmd, char **env)
{
	char 			**path;
	unsigned int	i;
	char			*concat;
	char			*tmp;
	char			*to_return;

	path = get_var_path_env(env, "PATH");
	i = 0;
	to_return = NULL;
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

t_cmd	get_cmd(char *argv_x, char **env, int code_error)
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
	real_path = whereis_cmd(cmd, env);
	to_return.cmd = real_path;
	to_return.arg = get_arg(to_return.arg, real_path, cmd);
	is_path_ok(to_return.arg[0], cmd, env, argv_x, code_error);
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
