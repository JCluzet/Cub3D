/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/06 00:44:17 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parse		parsee;
	t_display	displayy;

	if (argc == 1)
		return
		(showerror(&displayy, "No path to scene file have been provided.\n"));
	if (argc > 3)
		return
		(showerror(&displayy, "More than two argument have been provided.\n"));
	if (argc == 3 && cmp(argv[2], "--save", 6))
		return (showerror(&displayy, "Invalid second argument\n"));
	parse(argc, argv[1], &parsee, &displayy);
	display(&parsee, &displayy);
	return (EXIT_SUCCESS);
}
