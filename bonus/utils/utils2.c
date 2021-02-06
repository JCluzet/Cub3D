/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:50:21 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:41:13 by jcluzet          ###   ########.fr       */
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

unsigned int	addsmog(double dist, t_display *display)
{
	if (dist < 1)
		dist = 1;
	if (display->switchoff == 2)
	{
		display->rgbtemp[0] = display->rgbfloor[0] / dist;
		display->rgbtemp[1] = display->rgbfloor[1] / dist;
		display->rgbtemp[2] = display->rgbfloor[2] / dist;
		return (colortoint(display->rgbtemp[0],
		display->rgbtemp[1], display->rgbtemp[2]));
	}
	return (colortoint(display->rgbfloor[0],
	display->rgbfloor[1], display->rgbfloor[2]));
}

unsigned int	addsmog2(double dist, t_display *display)
{
	if (dist < 1)
		dist = 1;
	if (display->switchoff == 0)
	{
		display->rgbtemp[0] = display->rgbceiling[0] / dist;
		display->rgbtemp[1] = display->rgbceiling[1] / dist;
		display->rgbtemp[2] = display->rgbceiling[2] / dist;
		return (colortoint(display->rgbtemp[0], display->rgbtemp[1],
		display->rgbtemp[2]));
	}
	return (colortoint(display->rgbceiling[0], display->rgbceiling[1],
	display->rgbceiling[2]));
}
