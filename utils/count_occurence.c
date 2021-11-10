/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_occurence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:50:08 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/10 15:47:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	count_occurence(char *str, char *occurence)
{
	unsigned int	i;
	unsigned int	count;
	unsigned int	x;
	unsigned int	index_to_remember;

	i = 0;
	count = 0;
	index_to_remember = 0;
	while (str[i])
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
		i++;
	}
	if (count > 0)
		count++;
	return (count);
}
