/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:45:59 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:46:00 by sserbin          ###   ########.fr       */
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
