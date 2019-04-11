/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:47 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:50 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate(int keycode, t_mlx *e)
{
	if (keycode == 126)
		matrice('x', e->map, PI / 24);
	else if (keycode == 30)
		matrice('z', e->map, PI / 24);
	else if (keycode == 123)
		matrice('y', e->map, PI / 24);
	else if (keycode == 33)
		matrice('z', e->map, -1 * PI / 24);
	else if (keycode == 124)
		matrice('y', e->map, -1 * PI / 24);
	else if (keycode == 125)
		matrice('x', e->map, -1 * PI / 24);
}

static void	move_zoom(int keycode, t_mlx *e)
{
	if (keycode == 1)
		e->cam->cote_y += 10;
	else if (keycode == 2)
		e->cam->cote_x += 10;
	else if (keycode == 13)
		e->cam->cote_y -= 10;
	else if (keycode == 0)
		e->cam->cote_x -= 10;
	else if (keycode == 6 && e->cam->zoom > 1)
		e->cam->zoom -= 1;
	else if (keycode == 7)
		e->cam->zoom += 2;
	else if (keycode == 83)
		e->color = 1;
	else if (keycode == 84)
		e->color = 0;
}

int			deal_key(int key, t_mlx *e)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	move_zoom(key, e);
	rotate(key, e);
	draw(e, e->map);
	return (0);
}
