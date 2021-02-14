/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:14:15 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/14 15:56:28 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	minimap(t_display *display)
{
	int map_x;
	int map_y;

	map_x = 0;
	map_y = 0;
	display->minimap_x = 0;
	display->minimap_y = 0;
	while (map_y < display->mapy)
	{
		while (map_x <= display->mapx)
		{
			checkbox(display, display->map[map_y][map_x], map_x, map_y);
			map_x++;
		}
		map_y++;
		map_x = 0;
		display->minimap_y = display->sizeminimap * map_y;
		display->minimap_x = 0;
	}
}

void	checkbox(t_display *display, char c, int map_x, int map_y)
{
	display->color = 0;
	if (c == '0' || c == 'P')
		display->color = 16777215;
	if (c == '1')
		display->color = 1;
	if (c == '2')
		display->color = 8388736;
	if (c == '3')
		display->color = 8388100;
	if (c == '8')
		display->color = 984427;
	if (c == '4')
		display->color = 5229232;
	if ((int)display->player.x == map_x && (int)display->player.y == map_y)
		display->color = 13910590;
	drawsquare(display);
}

int		drawsquare(t_display *display)
{
	int i;
	int v;

	v = 0;
	i = 0;
	while (i < display->sizeminimap)
	{
		while (v < display->sizeminimap)
		{
			if (display->color != 0)
				put_pxl(display, display->minimap_x + v,
				display->minimap_y + i, display->color);
			v++;
		}
		v = 0;
		i++;
	}
	display->minimap_x += display->sizeminimap;
	return (0);
}

void	resizeminimap(t_display *display)
{
	if (display->r1 < 700 || display->r2 < 700)
		display->sizeminimap = 5;
	else if (display->r1 < 300 || display->r2 < 300)
		display->sizeminimap = 3;
	else
		display->sizeminimap = 10;
}
