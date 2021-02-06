/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:28:51 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:39:05 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotation(int i, t_display *display)
{
	double olddirx;
	double oldplanex;

	olddirx = display->dirx;
	display->dirx = display->dirx * cos(display->rotspeed * i)
		- display->diry * sin(display->rotspeed * i);
	display->diry = olddirx * sin(display->rotspeed * i)
		+ display->diry * cos(display->rotspeed * i);
	oldplanex = display->planex;
	display->planex = display->planex * cos(display->rotspeed * i)
		- display->planey * sin(display->rotspeed * i);
	display->planey = oldplanex * sin(display->rotspeed * i)
		+ display->planey * cos(display->rotspeed * i);
}

int		moveplayer(int nb, t_display *display)
{
	double tmpx;
	double tmpy;

	if (nb == 3)
	{
		tmpy = display->player.y + display->planey * display->pspeed;
		tmpx = display->player.x + display->planex * display->pspeed;
	}
	else if (nb == -1)
	{
		tmpx = display->player.x - ((display->pspeed * display->dirx));
		tmpy = display->player.y - ((display->pspeed * display->diry));
	}
	else if (nb == 1)
	{
		tmpx = display->player.x + ((display->pspeed * display->dirx));
		tmpy = display->player.y + ((display->pspeed * display->diry));
	}
	else
	{
		tmpy = display->player.y - display->planey * display->pspeed;
		tmpx = display->player.x - display->planex * display->pspeed;
	}
	return (moveornot(display, tmpx, tmpy));
}

int		moveornot(t_display *display, double tmpx, double tmpy)
{
	if (display->map[(int)display->player.y][(int)tmpx] != '1' &&
	display->map[(int)display->player.y][(int)tmpx] != '8')
		display->player.x = tmpx;
	if (display->map[(int)tmpy][(int)display->player.x] != '1' &&
	display->map[(int)tmpy][(int)display->player.x] != '8')
		display->player.y = tmpy;
	return (0);
}
