/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:50:21 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:44:06 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				ft_strlenght(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				arrondi(int number, int boleen)
{
	int index;

	index = 0;
	while (number > index)
		index++;
	if (boleen == 1)
		return (index);
	return (index - 1);
}

unsigned int	colortoint(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	color;

	color = r << 16 | g << 8 | b;
	return (color);
}
