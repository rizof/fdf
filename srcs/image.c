/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:40 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pixel_put(t_mlx *e, int x, int y, int i)
{
	int		pos;

	if (i > e->xmax * e->ymax)
		return ;
	if (e->design != 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->image->img_bpp / 8) + (y * e->image->img_size_line);
		e->image->img_data[pos] = e->design % 256;
		e->image->img_data[pos + 1] = (e->design >> 8) % 256;
		e->image->img_data[pos + 2] = (e->design >> 16) % 256;
	}
	else if (e->color != 0 && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->image->img_bpp / 8) + (y * e->image->img_size_line);
		e->image->img_data[pos] = e->map[i]->color % 256;
		e->image->img_data[pos + 1] = (e->map[i]->color >> 8) % 256;
		e->image->img_data[pos + 2] = (e->map[i]->color >> 16) % 256;
	}
	else if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->image->img_bpp / 8) + (y * e->image->img_size_line);
		e->image->img_data[pos] = e->map[i]->b;
		e->image->img_data[pos + 1] = e->map[i]->g;
		e->image->img_data[pos + 2] = e->map[i]->r;
	}
}

void	clear_image(t_mlx *e)
{
	mlx_destroy_image(e->mlx_ptr, e->image->img);
	e->image->img = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	e->image->img_data = mlx_get_data_addr(e->image->img, &(e->image->img_bpp),
		&(e->image->img_size_line), &(e->image->img_endian));
}
