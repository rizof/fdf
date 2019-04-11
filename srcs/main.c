/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		error(char *str)
{
	ft_putendl(str);
	return (0);
}

int		deal_hook(void *param)
{
	t_mlx *e;

	e = (t_mlx *)param;
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	design_windows(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image->img,
	0, 0);
	info(e);
	return (1);
}

int		main(int ac, char const *av[])
{
	t_mlx	e;

	if (ac == 2)
	{
		if (!malloc_struct(&e))
			return (error("warning malloc struct"));
		if ((e.map = reader_carte(&e, (char *)av[1], 0, 0)) == NULL)
			return (error("probleme carte"));
		init_size(&e);
	}
	else
		return (error("Usage : ./fdf <filename>"));
	if ((e.mlx_ptr = mlx_init()) == NULL)
		return (error("init error"));
	matrice('z', e.map, -1 * PI / 4);
	matrice('x', e.map, PI / 3);
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIDTH, HEIGHT, "FDF_RIZOF");
	e.image->img = mlx_new_image(e.mlx_ptr, WIDTH, HEIGHT);
	e.image->img_data = mlx_get_data_addr(e.image->img, &(e.image->img_bpp),\
	&(e.image->img_size_line), &(e.image->img_endian));
	draw(&e, e.map);
	mlx_key_hook(e.win_ptr, deal_key, &e);
	mlx_expose_hook(e.win_ptr, deal_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
