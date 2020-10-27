/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:18:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/26 18:58:31 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_checker(t_map *map, t_err *err, t_tex *tex, char **argv)
{
	int		fd;
	int		y;
	char	*line;

	line = NULL;
	y = 0;
	fd = ft_openfile(argv[1], err);
	if (fd < 0)
		return (-1);
	while ((y = get_next_line(fd, &line)) > 0 || (y = get_next_line(fd, &line)) == EOF)
	{
		y = ft_strlen(line);
		if (!(map->file = malloc (sizeof(char) * y + 1)))
			return (-1);
		map->file = ft_strdupb(line);
		if (ft_getdatafile(map, err, tex) < 0)
			return (-1);
		free(line);
		line = NULL;
		free(map->file);
		map->file = NULL;
	}
	return (0);
}

int				ft_getdatafile(t_map *map, t_err *err, t_tex *tex)
{
	int		y;

	y = 0;
	y = ft_outspace(y, map->file);
	if (ft_getres(map, err) < 0)
		return (-1);
	else if (ft_gettex(tex, err, map) < 0)
		return (-1);
	else if (ft_getsprite(tex, err, map) < 0)
		return (-1);
	else if (ft_getflo(tex, err, map) < 0)
		return (-1);
	else if (ft_getceil(tex, err, map) < 0)
		return (-1);
	else if (ft_checkall(map, tex) == 0)
		ft_getmap(map, err);
	return (0);
}

int				ft_getres(t_map *map, t_err *err)
{
	int		y;

	y = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y] == 'R')
	{
		map->res = map->res + 1;
		y++;
		y = ft_outspace(y, map->file);
		while (map->file[y] >= '0' && map->file[y] <= '9')
		{
			map->rx = map->rx * 10 + (map->file[y] - 48);
			y++;
		}
		y = ft_outspace(y, map->file);
		while (map->file[y] >= '0' && map->file[y] <= '9')
		{
			map->ry = map->ry * 10 + (map->file[y] - 48);
			y++;
		}
	}
	return (ft_checkres(map, err));
}

int				ft_checkres(t_map *map, t_err *err)
{
	if (map->res > 1)
	{
		ft_printerr(err->err14);
		return (-14);
	}
	if (map->rx > 2560 || map->ry > 1440)
	{
		map->rx = 2560;
		map->ry = 1440;
		return (0);
	}
	if (map->res == 0 || map->rx <= 0 || map->ry <= 0 || map->res > 1)
	{
		ft_printerr(err->err5);
		return (-5);
	}
	return (0);
}

int				ft_checkall(t_map *map, t_tex *tex)
{
	if (map->res == 1 && tex->ce == 1 && tex->fl == 1
		&& tex->no == 1 && tex->so == 1 && tex->we == 1
		&& tex->ea == 1 && tex->sp == 1)
		return (0);
	else
		return (-1);
}
