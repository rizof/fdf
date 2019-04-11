/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:47 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:50 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	check_long(t_mlx *e, int y)
{
	if (e->xmax == -1)
		e->xmax = y;
	if (e->xmax != y)
		return (1);
	return (0);
}

static int	parse_validmap(char **str, t_mlx *e, int y, int x)
{
	while (str[++y])
	{
		while (str[y][x])
			if (str[y][x] == ',')
			{
				x++;
				if (hexa(str[y], &x))
					return (error("color carte"));
			}
			else if (ft_isdigit(str[y][x]) ||\
			str[y][x] == '-' || str[y][x] == '+')
				x++;
			else
				return (error("color carte"));
		ft_strdel(&str[y]);
		x = 0;
	}
	free(str);
	if (check_long(e, y))
		return (0);
	return (1);
}

int			create_map(t_point ***map, t_mlx *e, char **tmp_map, int nb)
{
	int x;

	x = 0;
	while (tmp_map[x])
	{
		(*map)[nb] = malloc(sizeof(t_point));
		(*map)[nb]->y = e->y - e->ymax / 2;
		(*map)[nb]->x = x - e->xmax / 2;
		(*map)[nb]->z = ft_atoi(tmp_map[x]);
		(*map)[nb]->color = funccolor(tmp_map[x]);
		if (e->zmax <= ft_atoi(tmp_map[x]))
			e->zmax = ft_atoi(tmp_map[x]);
		ft_strdel(&tmp_map[x]);
		x++;
		nb++;
	}
	free(tmp_map);
	return (nb);
}

int			parsing_map(t_mlx *e, char *read, int y)
{
	int		fd;
	char	*line;

	if ((fd = open(read, O_RDONLY)) == -1)
		return (error("error read"));
	while (get_next_line(fd, &line) > 0)
	{
		if (!parse_validmap(ft_strsplit(line, ' '), e, -1, 0))
		{
			ft_strdel(&line);
			return (error("error width carte"));
		}
		ft_strdel(&line);
		y++;
	}
	ft_strdel(&line);
	e->ymax = y;
	close(fd);
	return (1);
}

t_point		**reader_carte(t_mlx *e, char *read, int y, int nb)
{
	int		fd;
	t_point	**map;
	char	*line;

	e->xmax = -1;
	e->zmax = -2147483648;
	parsing_map(e, read, y);
	if (!(map = malloc(e->xmax * e->ymax * sizeof(t_point))))
		return (NULL);
	if ((fd = open(read, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		nb = create_map(&map, e, ft_strsplit(line, ' '), nb);
		ft_strdel(&line);
		e->y++;
	}
	ft_strdel(&line);
	map[nb] = NULL;
	return (map);
}
