/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:40 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	function_color(t_mlx *e, int y, int y2, int x2)
{
	int x;

	x = 0;
	while (y < y2)
	{
		while (x < x2)
		{
			img_pixel_put(e, x, y, 0);
			x++;
		}
		x = 0;
		y++;
	}
}

void	info(t_mlx *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 540, 15, 0x00FFFFFF, "---- FdF ----");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 55, 910, 0x00FFFFFF, "< = rotation gauche");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 300, 910, 0x00FFFFFF, "> = rotation droite");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 55, 930, 0x00FFFFFF, "^ = rotation haut");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 300, 930, 0x00FFFFFF, "v = rotation bas");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 55, 950, 0x00FFFFFF, "] = pivoter droite");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 300, 950, 0x00FFFFFF, "[ = pivoter gauche");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 600, 910, 0x00FFFFFF, "q = gauche");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 800, 910, 0x00FFFFFF, "d = droite");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 600, 930, 0x00FFFFFF, "w = haut");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 800, 930, 0x00FFFFFF, "s = bas");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 600, 950, 0x00FFFFFF, "x = zoom");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 800, 950, 0x00FFFFFF, "z = dezoom");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 920, 930, 0x00FFFFFF, "1 = color default");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 920, 950, 0x00FFFFFF, "2 = color relief");
}

int		funccolor(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			i = ft_atoi_base(str + i + 3, 16);
			return (i);
		}
		i++;
	}
	return (COLOR_DEFAULT);
}

void	design_windows(t_mlx *e)
{
	int y;
	int x;

	y = 0;
	x = 0;
	e->design = 0x4A0404;
	function_color(e, 0, 100, 1200);
	e->design = 0x3B3B3B;
	function_color(e, 100, 103, 1200);
	function_color(e, 897, 900, 1200);
	e->design = 0x4A0404;
	function_color(e, 900, 1000, 1200);
	e->design = 0;
}
