/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:40 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	line1(t_point p1, t_point p2, t_mlx *e, int i)
{
	t_bresseham p;

	p.incr = ((double)(p2.py - p1.py) / ((double)p2.px - p1.px) > 1 ? 0 : 1);
	p.dx = (p.incr ? 2 * (p2.py - p1.py) : 2 * (p2.px - p1.px));
	p.dy = (p.incr ? 2 * (p2.py - p1.py) - (p2.px - p1.px)
			: 2 * (p2.px - p1.px) - (p2.py - p1.py));
	p.e = (p.incr ? 2 * ((p2.py - p1.py) - (p2.px - p1.px))
			: 2 * ((p2.px - p1.px) - (p2.py - p1.py)));
	while ((p1.px < p2.px && p.incr == 1) || (p1.py < p2.py && p.incr == 0))
	{
		img_pixel_put(e, p1.px, p1.py, i);
		if (p.dy <= 0)
			p.dy = p.dy + p.dx;
		else
		{
			p.incr ? p1.py++ : p1.px++;
			p.dy = p.dy + p.e;
		}
		p.incr ? p1.px++ : p1.py++;
	}
}

static void	line2(t_point p1, t_point p2, t_mlx *e, int i)
{
	t_bresseham p;

	p.incr = ((double)(p2.py - p1.py) / ((double)p1.px - p2.px) > 1 ? 0 : 1);
	p.dx = (p.incr ? 2 * (p2.py - p1.py) : 2 * (p1.px - p2.px));
	p.dy = (p.incr ? 2 * (p2.py - p1.py) - (p1.px - p2.px)
			: 2 * (p1.px - p2.px) - (p2.py - p1.py));
	p.e = (p.incr ? 2 * ((p2.py - p1.py) - (p1.px - p2.px))
			: 2 * ((p1.px - p2.px) - (p2.py - p1.py)));
	while ((p1.px > p2.px && p.incr == 1) || (p1.py < p2.py && p.incr == 0))
	{
		img_pixel_put(e, p1.px, p1.py, i);
		if (p.dy <= 0)
			p.dy = p.dy + p.dx;
		else
		{
			p.dy = p.dy + p.e;
			p.incr ? p1.py++ : p1.px--;
		}
		p.incr ? p1.px-- : p1.py++;
	}
}

static void	line3(t_point p1, t_point p2, t_mlx *e, int i)
{
	t_bresseham p;

	p.incr = ((double)(p1.py - p2.py) / ((double)p2.px - p1.px) > 1 ? 0 : 1);
	p.dx = (p.incr ? 2 * (p1.py - p2.py) : 2 * (p2.px - p1.px));
	p.dy = (p.incr ? 2 * (p1.py - p2.py) - (p2.px - p1.px)
			: 2 * (p2.px - p1.px) - (p1.py - p2.py));
	p.e = (p.incr ? 2 * ((p1.py - p2.py) - (p2.px - p1.px))
			: 2 * ((p2.px - p1.px) - (p1.py - p2.py)));
	while ((p1.px < p2.px && p.incr == 1) || (p1.py > p2.py && p.incr == 0))
	{
		img_pixel_put(e, p1.px, p1.py, i);
		if (p.dy <= 0)
			p.dy = p.dy + p.dx;
		else
		{
			p.dy = p.dy + p.e;
			p.incr ? p1.py-- : p1.px++;
		}
		p.incr ? p1.px++ : p1.py--;
	}
}

static void	line4(t_point p1, t_point p2, t_mlx *e, int i)
{
	t_bresseham p;

	p.incr = ((double)(p1.py - p2.py) / ((double)p1.px - p2.px) > 1 ? 0 : 1);
	p.dx = (p.incr ? 2 * (p1.py - p2.py) : 2 * (p1.px - p2.px));
	p.dy = (p.incr ? 2 * (p1.py - p2.py) - (p1.px - p2.px)
			: 2 * (p1.px - p2.px) - (p1.py - p2.py));
	p.e = (p.incr ? 2 * ((p1.py - p2.py) - (p1.px - p2.px))
			: 2 * ((p1.px - p2.px) - (p1.py - p2.py)));
	while ((p1.px > p2.px && p.incr == 1) || (p1.py > p2.py && p.incr == 0))
	{
		img_pixel_put(e, p1.px, p1.py, i);
		if (p.dy <= 0)
			p.dy = p.dy + p.dx;
		else
		{
			p.incr ? p1.py-- : p1.px--;
			p.dy = p.dy + p.e;
		}
		p.incr ? p1.px-- : p1.py--;
	}
}

void		routeur_line(t_mlx *e, t_point p1, t_point p2, int i)
{
	if (p1.px < p2.px && p1.py <= p2.py)
		line1(p1, p2, e, i);
	else if (p1.py <= p2.py && p2.px < p1.px)
		line2(p1, p2, e, i);
	else if (p1.px < p2.px && p2.py <= p1.py)
		line3(p1, p2, e, i);
	else if (p2.py <= p1.py && p2.px < p1.px)
		line4(p1, p2, e, i);
}
