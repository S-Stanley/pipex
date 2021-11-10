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

void	check_if_real_path_ok(char *real_path, char **cmd)
{
	if (!real_path)
	{
		free_that_matrice(cmd);
		str_write("No path in env variable");
		exit(0);
	}
}
