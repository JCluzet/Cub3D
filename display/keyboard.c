/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:54:37 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/16 01:47:10 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_key_hit(int keycode, t_display *display)
{
	display->keyboard[keycode] = 1;
	return (0);
}

int		ft_key_release(int keycode, t_display *display)
{
	display->keyboard[keycode] = 0;
	return (0);
}

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
	return (0);
}

int		closebyredbutton(t_display *display)
{
	display->keyboard[RED_BUTTON] = 1;
	return (0);
}
