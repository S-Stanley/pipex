/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:46:14 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/10 15:35:13 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

typedef	struct s_return_value {
	char	*str;
	int	i;
}		t_return_value;

char	**get_malloc(unsigned int size, char *to_split, char*splitter)
{
	char **to_return;

	to_return = malloc(sizeof(char *) * (count_occurence(to_split, splitter) + 1));
	if (!to_return)
	{
		str_write("Error allocation in ft_split");
		exit(1);
	}
}

t_return_value	get_value(char *to_split, int i, char *splitter)
{
	char		*str;
	unsigned int	x;
	t_return_value	to_return;

	x = 0;
	str = malloc(sizeof(char) * ( + 1));
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

void	read_matrice(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		str_write(str[i]);
		str_write("\n");
		i++;
	}
}

char	**ft_split(char *to_split, char *splitter)
{
	char		**to_return;
	unsigned int	i;
	unsigned int	x;
	t_return_value	splitted;

	to_return = get_malloc(count_occurence(to_split, splitter), to_split, splitter);
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
	read_matrice(to_return);
	return (to_return);
}
