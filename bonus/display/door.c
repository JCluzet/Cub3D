/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:39:12 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	opendoor(t_display *display)
{
	if (display->map[display->mapi.y][display->mapi.x] == '8')
		display->map[display->mapi.y][display->mapi.x] = '0';
	if (display->map[display->mapi.y + 1][display->mapi.x] == '8')
		display->map[display->mapi.y + 1][display->mapi.x] = '0';
	if (display->map[display->mapi.y - 1][display->mapi.x] == '8')
		display->map[display->mapi.y - 1][display->mapi.x] = '0';
	if (display->map[display->mapi.y][display->mapi.x + 1] == '8')
		display->map[display->mapi.y][display->mapi.x + 1] = '0';
	if (display->map[display->mapi.y][display->mapi.x + 1] == '8')
		display->map[display->mapi.y][display->mapi.x + 1] = '0';
	return (0);
}
