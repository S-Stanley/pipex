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

int	ft_count(const char *str, char c)
{
	int		i;
	int		count;
	int		size;

	if (!str)
		return (0);
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
	int	start;

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

	res = malloc(sizeof(char *) * ft_count(str, c));
	if (!res || !str)
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
