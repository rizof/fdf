/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:40 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line_push(t_point p1, t_point p2, t_mlx *e, int i)
{
	int x;
	int y;
	int m;

	m = (p1.py < p2.py) ? p1.py : p2.py;
	y = (p1.py > p2.py) ? p1.py : p2.py;
	x = (p1.px > p2.px) ? p1.px : p2.px;
	if (p1.px == p2.px)
	{
		while (y <= m)
		{
			img_pixel_put(e, x, y, i);
			y++;
		}
		return ;
	}
	routeur_line(e, p1, p2, i);
}

void	draw(t_mlx *e, t_point **map)
{
	int i;

	i = 0;
	clear_image(e);
	init_moove(e);
	while (map[i] != NULL)
	{
		if ((i + 1) % e->xmax != 0)
			line_push(*(map[i]), *(map[i + 1]), e, i);
		if (i < e->xmax * (e->ymax - 1))
			line_push(*(map[i]), *(map[i + e->xmax]), e, i);
		i++;
	}
	design_windows(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image->img,
	0, 0);
	info(e);
}
