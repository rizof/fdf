/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:47 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:50 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# define WIDTH 1200
# define HEIGHT 1000
# define PI 3.141592653589793
# define COLOR_DEFAULT 0XFFFF

typedef	struct		s_bresseham
{
	int				dx;
	int				dy;
	int				incr;
	int				e;
}					t_bresseham;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				px;
	int				py;
	int				color;
	int				r;
	int				g;
	int				b;
}					t_point;

typedef struct		s_cam
{
	int				cote_y;
	int				cote_x;
	int				zoom;
	int				z_size;
}					t_cam;

typedef struct		s_image
{
	void			*img;
	char			*img_data;
	int				img_bpp;
	int				img_size_line;
	int				img_endian;
}					t_image;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	int				xmax;
	int				ymax;
	int				zmax;
	int				design;
	int				color;
	int				y;
	t_point			**map;
	t_cam			*cam;
	t_image			*image;
}					t_mlx;

typedef struct		s_v4d
{
	double			x;
	double			y;
	double			z;
}					t_v4d;

typedef struct		s_m4
{
	t_v4d			x;
	t_v4d			y;
	t_v4d			z;
}					t_m4;

void				matrice(char axe, t_point **point, double theta);
int					expose_hook(t_mlx *e);
int					deal_key(int key, t_mlx *e);
int					error(char *str);
void				init_size(t_mlx *e);
int					malloc_struct(t_mlx *e);
t_point				**reader_carte(t_mlx *e, char *read, int y, int nb);
void				design_windows(t_mlx *e);
void				draw(t_mlx *e, t_point **tab);
int					funccolor(char *str);
int					error(char *str);
void				init_moove(t_mlx *e);
void				img_pixel_put(t_mlx *e, int x, int y, int color);
void				info(t_mlx *e);
void				routeur_line(t_mlx *e, t_point p1, t_point p2, int i);
void				clear_image(t_mlx *e);
#endif
