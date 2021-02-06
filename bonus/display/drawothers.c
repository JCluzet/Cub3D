/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawothers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:40:08 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawgun(t_display *display)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < display->heighttext[4])
	{
		while (x < display->widthtext[4])
		{
			display->color = *(unsigned int*)
			(display->ptr[4] + display->s_line2[4]
			* y + x * (display->bpp2[4] / 8));
			if (display->color != 0 && y < 150)
				put_pxl(display, display->r1 / 2 + x,
				display->r2 - 150 + y, display->color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	drawlife(t_display *display)
{
	int		x;
	int		y;
	double	life;

	life = (display->life / 100);
	life = life * 190;
	x = 0;
	y = 0;
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
