/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:40:36 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		floodandfill(t_display *display, int mapy, int mapx)
{
	if (display->map[mapy][mapx] == '9' ||
	display->map[mapy][mapx] == 's' || display->map[mapy][mapx] == 'd'
	|| display->map[mapy][mapx] == '4' || display->map[mapy][mapx] == 'S')
	{
		if (checkaround(mapx, mapy, display) == 0)
			showerror(display, "Map is not surrounded/closed by walls");
		if (display->map[mapy][mapx] == 's')
			display->map[mapy][mapx] = '2';
		if (display->map[mapy][mapx] == '4')
			display->map[mapy][mapx] = 'k';
		if (display->map[mapy][mapx] == 'S')
			display->map[mapy][mapx] = '3';
		if (display->map[mapy][mapx] == 'd')
			display->map[mapy][mapx] = '8';
		if (display->map[mapy][mapx] == '9')
			display->map[mapy][mapx] = '0';
		floodandfill(display, mapy, mapx + 1);
		floodandfill(display, mapy, mapx - 1);
		floodandfill(display, mapy + 1, mapx);
		floodandfill(display, mapy - 1, mapx);
	}
	return (1);
}

int		checkifgood(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != '8' && c != 'P'
	&& c != '9' && c != 's' && c != 'd' && c != 'S'
	&& c != '3' && c != '4' && c != 'k')
		return (0);
	return (1);
}

int		checkifgood2(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != ' '
	&& c != '3' && c != '8' && c != 'N' && c != 'W'
	&& c != 'E' && c != 'S' && c != 'k')
		return (0);
	return (1);
}

int		checkaround(int mapx, int mapy, t_display *display)
{
	if (mapy == 0 || mapy == display->mapy - 1
	|| mapx == 0 || mapx == display->mapx - 1)
		showerror(display, "Map is not surrounded/closed by walls");
	if (checkifgood(display->map[mapy + 1][mapx]) == 0)
		return (0);
	if (checkifgood(display->map[mapy - 1][mapx]) == 0)
		return (0);
	if (checkifgood(display->map[mapy][mapx + 1]) == 0)
		return (0);
	if (checkifgood(display->map[mapy][mapx - 1]) == 0)
		return (0);
	return (1);
}

int		checkthewall(t_display *display)
{
	int mapx;
	int mapy;

	mapy = (int)display->player.x;
	mapx = (int)display->player.y;
	if (display->numberofplayer == 0)
		showerror(display, "Missing player on the map");
	if (display->numberofplayer > 1)
		showerror(display, "Multiplayer mode isn't available");
	floodandfill(display, mapx, mapy + 1);
	floodandfill(display, mapx, mapy - 1);
	floodandfill(display, mapx + 1, mapy);
	floodandfill(display, mapx, mapy - 1);
	mapx = 0;
	mapy = 0;
	return (0);
}
