/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:18:48 by fballest          #+#    #+#             */
/*   Updated: 2020/11/25 13:51:32 by fballest         ###   ########.fr       */
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
	ft_countlines(argv[1], map, err);
	fd = ft_openfile(argv[1], err);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line)
			map->file = ft_strdupb(line);
		free(line);
		line = NULL;
		map->im++;
		if (ft_getdatafile(map, err, tex) < 0)
			return (-1);
	}
	map->file = ft_strdupb(line);
	free(line);
	line = NULL;
	map->im++;
	if (ft_getdatafile(map, err, tex) < 0 || ft_checkokmap(map, tex, err) < 0)
		return (-1);
	return (0);
}

int				ft_getdatafile(t_map *map, t_err *err, t_tex *tex)
{
	int		y;

	y = ft_outemptylines(map);
	if (y < 0 && map->okmap == 1)
	{
		ft_printerr(err->err9);
		exit(-9);
	}
	if (y < 0)
		return (0);
	y = ft_outspace(y, map->file);
	if (ft_getdatafileb(map, tex, err) < 0)
		return (-1);
	if (map->res > 1 || tex->ce > 1 || tex->fl > 1 || tex->no > 1
		|| tex->so > 1 || tex->we > 1 || tex->ea > 1 || tex->sp > 1)
	{
		ft_printerr(err->err14);
		exit(-14);
	}
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
		ft_checknumbers(map, err);
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
	if (map->res == 0)
		return (0);
	else if (map->res > 1)
	{
		ft_printerr(err->err14);
		exit(-14);
	}
	else if (map->res == 1 && (map->rx <= 0 || map->ry <= 0))
	{
		ft_printerr(err->err5);
		exit(-5);
	}
	else if (map->res == 1 && (map->rx > 2560 || map->ry > 1440))
	{
		map->rx = 2560;
		map->ry = 1440;
		return (0);
	}
	return (0);
}

int				ft_checkall(t_map *map, t_err *err)
{
	int		y;

	y = 0;
	while (map->file[y] != '\0')
	{
		if (map->file[y] == ' ' || map->file[y] == '1' || map->file[y] == '0'
			|| map->file[y] == '2' || map->file[y] == 'N' || map->file[y] == 'S'
			|| map->file[y] == 'W' || map->file[y] == 'E'
			|| map->file[y] == '\t')
			y++;
		else
		{
			ft_printerr(err->err18);
			exit(-18);
		}
	}
	return (0);
}
