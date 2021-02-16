/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:54:37 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/16 02:21:49 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_keyboard(t_display *display)
{
	if (display->keyboard[ADVANCE])
		moveplayer(1, display);
	if (display->keyboard[BACK])
		moveplayer(-1, display);
	if (display->keyboard[LEFT])
		moveplayer(2, display);
	if (display->keyboard[RIGHT])
		moveplayer(3, display);
	if (display->keyboard[ROT_RIGHT])
		rotation(-1, display);
	if (display->keyboard[ROT_LEFT])
		rotation(1, display);
	if (display->keyboard[ESC] || display->keyboard[RED_BUTTON])
		freeandexit(display);
	checkkeybonus(display);
	return (0);
}

void	checkkeybonus(t_display *display)
{
	if (display->keyboard[LIGHTS])
	{
		if (display->switchoff == 1)
			display->switchoff = 0;
		else
			display->switchoff = 1;
	}
	if (display->keyboard[OPEN_DOOR])
		opendoor(display);
}

int		closebyredbutton(t_display *display)
{
	display->keyboard[RED_BUTTON] = 1;
	return (0);
}
