/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_occurence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:45:54 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:45:54 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	count_occ(char *str, char *occurence)
{
	int		i;
	unsigned int	count;
	unsigned int	x;
	unsigned int	index_to_remember;

	i = -1;
	count = 0;
	index_to_remember = 0;
	while (str[++i])
	{
		x = 0;
		index_to_remember = i;
		while (str[i] == occurence[x])
		{
			x++;
			i++;
		}
		if (x >= ft_strlen(occurence))
			count++;
		else
			i = index_to_remember;
	}
	if (count > 0)
		count++;
	return (count);
}
