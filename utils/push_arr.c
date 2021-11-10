/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:46:16 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:46:16 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	count_len_array(char **arr)
{
	unsigned int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	**push_arr(char **arr, char *to_add)
{
	unsigned int	i;
	char			**to_return;

	i = 0;
	to_return = malloc(sizeof(char *) * (count_len_array(arr) + 2));
	if (!to_return)
		return (NULL);
	if (arr)
	{
		while (arr[i])
		{
			to_return[i] = arr[i];
			i++;
		}
		free(arr);
	}
	to_return[i] = to_add;
	to_return[++i] = 0;
	return (to_return);
}
