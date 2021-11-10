/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:40:02 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/10 16:47:31 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*ft_concat(char *str1, char *str2)
{
	unsigned int	i;
	unsigned int	x;
	char			*to_return;

	to_return = malloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!to_return)
		return (NULL);
	i = 0;
	x = 0;
	while (str1[i])
	{
		to_return[i] = str1[i];
		i++;
	}
	while (str2[x])
	{
		to_return[i] = str2[x];
		i++;
		x++;
	}
	to_return[i] = 0;
	return (to_return);
}
