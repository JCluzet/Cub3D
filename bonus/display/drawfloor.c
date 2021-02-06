/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfloor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by jocluzet          #+#    #+#             */
/*   Updated: 2021/02/06 00:40:04 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		drawfloor(t_display *display)
{
	int x;
	int y;

	y = display->r2 / 2;
	while (y < display->r2)
	{
		getverticaldata(display, y);
		x = 0;
		while (x < display->r1)
		{
			gethorizontaldata(display);
			display->color = addsmog3(display->rowdistance,
				display, display->color);
			put_pxl(display, x, y, display->color);
			x++;
		}
		y++;
	}
	return (1);
}

int		gethorizontaldata(t_display *display)
{
	display->cellx = (int)display->floorx;
	display->celly = (int)display->floory;
	display->txfloor = (int)(display->widthtext[8] *
	(display->floorx - display->cellx)) & (display->widthtext[8] - 1);
	display->tyfloor = (int)(display->heighttext[8] *
	(display->floory - display->celly)) & (display->heighttext[8] - 1);
	display->txfloor2 = (int)(display->widthtext[9] *
	(display->floorx - display->cellx)) & (display->widthtext[9] - 1);
	display->tyfloor2 = (int)(display->heighttext[9] *
	(display->floory - display->celly)) & (display->heighttext[9] - 1);
	display->floorx += display->floorstepx;
	display->floory += display->floorstepy;
	display->color = *(unsigned int *)(display->ptr[8] +
	display->s_line2[8] * display->tyfloor +
	display->txfloor * (display->bpp2[8] / 8));
	display->color = (display->color >> 1) & 8355711;
	return (0);
}

int		getverticaldata(t_display *display, int y)
{
	display->raydirx0 = display->dirx - display->planex;
	display->raydiry0 = display->diry - display->planey;
	display->raydirx1 = display->dirx + display->planex;
	display->raydiry1 = display->diry + display->planey;
	display->pfloor = y - display->r2 / 2;
	display->posz = 0.5 * display->r2;
	display->rowdistance = display->posz / display->pfloor;
	display->floorstepx = display->rowdistance *
	(display->raydirx1 - display->raydirx0) / display->r1;
	display->floorstepy = display->rowdistance *
	(display->raydiry1 - display->raydiry0) / display->r1;
	display->floorx = display->player.x +
	display->rowdistance * display->raydirx0;
	display->floory = display->player.y +
	display->rowdistance * display->raydiry0;
	return (0);
}
