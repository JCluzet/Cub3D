/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtextures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/12 02:52:07 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loadtextures(t_display *display)
{
	if ((display->text_no = mlx_xpm_file_to_image(display->mlx_ptr,
	display->north, &display->widthtext[0], &display->heighttext[0])))
		display->ptr[0] = mlx_get_data_addr(display->text_no,
		&(display->bpp2[0]), &(display->s_line2[0]), &(display->ed2[0]));
	if ((display->text_so = mlx_xpm_file_to_image(display->mlx_ptr,
	display->south, &display->widthtext[1], &display->heighttext[1])))
		display->ptr[1] = mlx_get_data_addr(display->text_so,
		&(display->bpp2[1]), &(display->s_line2[1]), &(display->ed2[1]));
	if ((display->text_we = mlx_xpm_file_to_image(display->mlx_ptr,
	display->west, &display->widthtext[2], &display->heighttext[2])))
		display->ptr[2] = mlx_get_data_addr(display->text_we,
		&(display->bpp2[2]), &(display->s_line2[2]), &(display->ed2[2]));
	if ((display->text_ea = mlx_xpm_file_to_image(display->mlx_ptr,
	display->east, &display->widthtext[3], &display->heighttext[3])))
		display->ptr[3] = mlx_get_data_addr(display->text_ea,
		&(display->bpp2[3]), &(display->s_line2[3]), &(display->ed2[3]));
	loadtexturesbonus(display);
}

void	checksizetext(t_display *display)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (display->widthtext[i] > 64 || display->heighttext[i] > 64)
			showerror(display, "Wall textures max is 64 x 64 pixels");
		i++;
	}
}

void	loadtexturesbonus(t_display *display)
{
	if ((display->text_gun = mlx_xpm_file_to_image(display->mlx_ptr,
	"./textures/weapon.xpm", &display->widthtext[4], &display->heighttext[4])))
		display->ptr[4] = mlx_get_data_addr(display->text_gun,
		&(display->bpp2[4]), &(display->s_line2[4]), &(display->ed2[4]));
	if ((display->text_door = mlx_xpm_file_to_image(display->mlx_ptr,
	"./textures/Door.xpm", &display->widthtext[6], &display->heighttext[6])))
		display->ptr[6] = mlx_get_data_addr(display->text_door,
		&(display->bpp2[6]), &(display->s_line2[6]), &(display->ed2[6]));
	if ((display->text_floor = mlx_xpm_file_to_image(display->mlx_ptr,
	"./textures/floor.xpm", &display->widthtext[8], &display->heighttext[8])))
		display->ptr[8] = mlx_get_data_addr(display->text_floor,
		&(display->bpp2[8]), &(display->s_line2[8]), &(display->ed2[8]));
	if ((display->text_life = mlx_xpm_file_to_image(display->mlx_ptr,
	"./textures/lifeup.xpm", &display->widthtext[7], &display->heighttext[7])))
		display->ptr[7] = mlx_get_data_addr(display->text_life,
		&(display->bpp2[7]), &(display->s_line2[7]), &(display->ed2[7]));
	resizelife(display);
}

void	resizelife(t_display *display)
{
	checksizetext(display);
	if (display->r1 < 1100 && display->r2 < 1100)
	{
		display->heighttext[7] = display->heighttext[7] / 4;
		display->widthtext[7] = display->widthtext[7] / 4;
	}
}
