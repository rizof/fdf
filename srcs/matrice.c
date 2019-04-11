/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:40 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mat(t_m4 *e, t_point *p)
{
	t_point d;

	d.x = p->x * e->x.x + p->y * e->x.y + p->z * e->x.z;
	d.y = p->x * e->y.x + p->y * e->y.y + p->z * e->y.z;
	d.z = p->x * e->z.x + p->y * e->z.y + p->z * e->z.z;
	p->x = d.x;
	p->y = d.y;
	p->z = d.z;
}

t_m4		init_z(double alpha)
{
	return ((t_m4) {
		(t_v4d){cos(alpha), -1 * sin(alpha), 0},
		(t_v4d){sin(alpha), cos(alpha), 0},
		(t_v4d){0, 0, 1}
	});
}

t_m4		init_y(double alpha)
{
	return ((t_m4) {
		(t_v4d){cos(alpha), 0, sin(alpha)},
		(t_v4d){0, 1, 0},
		(t_v4d){-1 * sin(alpha), 0, cos(alpha)}
	});
}

t_m4		init_x(double alpha)
{
	return ((t_m4) {
		(t_v4d){1, 0, 0},
		(t_v4d){0, cos(alpha), -1 * sin(alpha)},
		(t_v4d){0, sin(alpha), cos(alpha)}
	});
}

void		matrice(char c, t_point **point, double alpha)
{
	int		p;
	t_m4	e;

	p = 0;
	if (c == 'z')
		e = init_z(alpha);
	if (c == 'y')
		e = init_y(alpha);
	if (c == 'x')
		e = init_x(alpha);
	while (point[p] != NULL)
	{
		mat(&e, point[p]);
		p++;
	}
}
