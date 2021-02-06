/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:50:21 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:41:17 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				switchspriteforsort(t_display *display, int index)
{
	double	disttemp;
	int		spritetemp;

	disttemp = display->spritedist[index];
	display->spritedist[index] = display->spritedist[index - 1];
	display->spritedist[index - 1] = disttemp;
	spritetemp = display->spritex[index];
	display->spritex[index] = display->spritex[index - 1];
	display->spritex[index - 1] = spritetemp;
	spritetemp = display->spritey[index];
	display->spritey[index] = display->spritey[index - 1];
	display->spritey[index - 1] = spritetemp;
	spritetemp = display->spritenum[index];
	display->spritenum[index] = display->spritenum[index - 1];
	display->spritenum[index - 1] = spritetemp;
	return (0);
}

int				isend(char *line)
{
	int i;

	i = 0;
	if (is_space(line[i]))
	{
		i = numberblank(line + i);
		if (line[i] == '\n')
			return (1);
	}
	return (0);
}

int				searchcomma(char *line)
{
	int i;

	i = 0;
	while (((line[i] != '\n' || line[i] != '\0') && i < 4) || is_space(line[i]))
	{
		if (line[i] == ',')
			return (i + 1);
		i++;
	}
	if (line[i] == ',')
		return (i + 1);
	return (-1);
}

unsigned int	addsmog3(double dist, t_display *display, unsigned int color)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	r = (color >> 0) & 255;
	g = (color >> 8) & 255;
	b = (color >> 16) & 255;
	if (dist < 1 || display->switchoff == 1)
		dist = 1;
	display->rgbtemp[0] = b / dist;
	display->rgbtemp[1] = g / dist;
	display->rgbtemp[2] = r / dist;
	return (colortoint(display->rgbtemp[0], display->rgbtemp[1],
	display->rgbtemp[2]));
}

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!src || !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		++i;
	}
	return (dest);
}
