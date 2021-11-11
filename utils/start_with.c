/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_with.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:52:28 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/11 12:52:28 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	start_with(char *str, char *occurence)
{
	unsigned int	i;

	i = 0;
	while (occurence[i])
	{
		if (str[i] != occurence[i])
			return (0);
		i++;
	}
	return (1);
}
