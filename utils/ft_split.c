/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:46:07 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:46:08 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**get_malloc(unsigned int size)
{
	char	**to_return;

	to_return = malloc(sizeof(char *) * (size + 2));
	if (!to_return)
	{
		str_write("Error allocation in ft_split");
		exit(1);
	}
	return (to_return);
}

unsigned int	count_next_occ(char *to_split, int i, char *splitter)
{
	unsigned int	count;

	count = 0;
	if (to_split[i] == splitter[0])
		i++;
	while (to_split[i] && to_split[i] != splitter[0])
	{
		i++;
		count++;
	}
	return (count);
}

t_return_value	get_value(char *to_split, int i, char *splitter)
{
	char			*str;
	unsigned int	x;
	t_return_value	to_return;

	x = 0;
	str = malloc(sizeof(char) * (count_next_occ(to_split, i, splitter) + 1));
	if (!str)
	{
		to_return.str = NULL;
		return (to_return);
	}
	if (to_split[i] == splitter[0])
		i++;
	while (to_split[i] && to_split[i] != splitter[0])
	{
		str[x] = to_split[i];
		i++;
		x++;
	}
	str[x] = 0;
	to_return.str = str;
	to_return.i = i;
	return (to_return);
}

char	**ft_split(char *to_split, char *splitter)
{
	char			**to_return;
	unsigned int	i;
	unsigned int	x;
	t_return_value	splitted;

	to_return = get_malloc(count_occ(to_split, splitter));
	i = 0;
	x = 0;
	while (i < ft_strlen(to_split))
	{
		splitted = get_value(to_split, i, splitter);
		if (!splitted.str)
		{
			free(to_return);
			exit(1);
		}
		i = splitted.i;
		to_return[x] = splitted.str;
		x++;
	}
	to_return[x] = 0;
	return (to_return);
}
