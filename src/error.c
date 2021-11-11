/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:54:07 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:54:08 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	is_path_ok(char *real_path, char **cmd, char **env, char *str)
{
	char	*shell;
	char	**cmd_to_print;

	if (!real_path)
	{
		shell = get_shell(env);
		cmd_to_print = ft_split(str, ' ');
		free_that_matrice(cmd);
		str_write(shell);
		free(shell);
		str_write(": command not found: ");
		str_write(cmd_to_print[0]);
		free_that_matrice(cmd_to_print);
		return (1);
	}
	return (0);
}
