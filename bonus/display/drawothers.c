/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawothers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/16 03:05:39 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawgun(t_display *display)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (display->keyboard[GUN])
		display->shoot = 1;
	getgunnum(display);
	while (y < display->heighttext[display->gunnum])
	{
		while (x < display->widthtext[display->gunnum])
		{
			display->color = *(unsigned int*)
			(display->ptr[display->gunnum] + display->s_line2[display->gunnum]
			* y + x * (display->bpp2[display->gunnum] / 8));
			if (display->color != 0 && y < 150)
				put_pxl(display, display->r1 / 2 + x,
				display->r2 - 150 + y, display->color);
			x++;
		}
		x = 0;
		y++;
	}
}

int		getgunnum(t_display *display)
{
	if (display->gunnum == 14 && display->shoot == 1)
	{
		display->gunnum = 15;
		display->inprocess = 1;
	}
	if (display->gunnum == 15 && display->inprocess == 0)
	{
		display->inprocess = 0;
		display->gunnum = 16;
	}
	if (display->gunnum == 16 && display->inprocess == 0)
	{
		display->gunnum = 14;
		display->shoot = 0;
	}
	display->inprocess = 0;
	return (0);
}

void	drawlife(t_display *display)
{
	int		x;
	int		y;
	double	life;

	get_life(display);
	life = (display->life / 100) * 190;
	x = 0;
	y = 0;
	raycasting(display);
	if (display->spritecounted != 0)
		showsprite(display);
	while (y < 70)
	{
		while (x < life)
		{
			display->color = *(unsigned int*)
			(display->ptr[7] + display->s_line2[7]
			* y + x * (display->bpp2[7] / 8));
			if (display->color != 0 && y < 150)
				put_pxl(display, display->r1 - 190 + x, y, display->color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	get_life(t_display *display)
{
	if (display->life < 0.1)
	{
		printf("\033[31m\n --- GAME OVER --- \n");
		freeandexit(display);
	}
	if (display->map[(int)display->player.y][(int)display->player.x] == '4')
		display->life = display->life - 0.1;
}
