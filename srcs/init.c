/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:00 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:01 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			malloc_struct(t_mlx *e)
{
	if ((e->cam = ft_memalloc(sizeof(t_cam))) &&\
		(e->image = ft_memalloc(sizeof(t_image))))
		return (1);
	return (0);
}

void		init_color(t_mlx *e, float res, int i)
{
	e->map[i]->r = 0;
	e->map[i]->g = 204;
	e->map[i]->b = 0;
	res = (float)e->map[i]->z / (float)e->zmax;
	if (res > 0.5)
	{
		e->map[i]->g = 204 * (res - 1);
		e->map[i]->r = 204 * res;
	}
	else if (res < 0.5 && res > 0)
	{
		e->map[i]->r = 204 * res;
		e->map[i]->g = 204 * res * 2;
	}
	else if (res <= 0)
	{
		e->map[i]->r = 2;
		e->map[i]->g = 20;
		e->map[i]->b = 240;
	}
	i++;
}

void		init_size(t_mlx *e)
{
	int i;

	i = 0;
	while (e->map[i])
	{
		init_color(e, 0, i);
		i++;
	}
	if (e->xmax <= 8 && e->ymax <= 8)
		e->cam->zoom = 100;
	if (e->xmax <= 16 && e->ymax <= 16 && e->zmax <= 10)
		e->cam->zoom = 50;
	else if (e->xmax <= 32 && e->ymax <= 32 && e->zmax <= 30)
		e->cam->zoom = 30;
	else if (e->xmax <= 64 && e->ymax <= 64 && e->zmax <= 50)
		e->cam->zoom = 10;
	else if (e->xmax <= 128 && e->ymax <= 128 && e->zmax <= 70)
		e->cam->zoom = 7;
	else if (e->xmax <= 250 && e->ymax <= 250 && e->zmax <= 80)
		e->cam->zoom = 4;
	else if (e->xmax <= 350 && e->ymax <= 350 && e->zmax <= 100)
		e->cam->zoom = 3;
	else
		e->cam->zoom = 2;
}

void		init_moove(t_mlx *e)
{
	int i;

	i = 0;
	while (e->map[i])
	{
		e->map[i]->px = (int)((e->map[i]->x) * e->cam->zoom\
		+ WIDTH / 2 + e->cam->cote_x);
		e->map[i]->py = (int)((e->map[i]->y) * e->cam->zoom\
		+ HEIGHT / 2 + e->cam->cote_y);
		i++;
	}
}
