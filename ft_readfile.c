/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:18:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/29 10:51:28 by fballest         ###   ########.fr       */
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
	map->fd = fd;
	if (fd < 0)
		return (-1);
	while ((get_next_line(fd, &line)) > 0
		|| (get_next_line(fd, &line)) == EOF)
	{
		y = ft_strlen(line);
		if (!(map->file = malloc(sizeof(char) * y + 1)))
			return (-1);
		map->file = ft_strdupb(line);
		free(line);
		line = NULL;
		if (ft_getdatafile(map, err, tex) < 0)
			return (-1);
	}
	return (0);
}

int				ft_getdatafile(t_map *map, t_err *err, t_tex *tex)
{
	int		y;

	y = 0;
	y = ft_outspace(y, map->file);
	if (map->res > 0 && tex->ce > 0 && tex->fl > 0 && tex->no > 0
		&& tex->so > 0 && tex->we > 0 && tex->ea > 0 && tex->sp > 0)
	{
		if (ft_checkall(map, err) == 0)
			ft_getmap(map, err, tex);
		else
			return (-1);
	}
	else if (ft_getres(map, err) < 0 && map->okmap == 0)
		return (-1);
	else if (ft_gettex(tex, err, map) < 0 && map->okmap == 0)
		return (-1);
	else if (ft_getsprite(tex, err, map) < 0 && map->okmap == 0)
		return (-1);
	else if (ft_getflo(tex, err, map) < 0 && map->okmap == 0)
		return (-1);
	else if (ft_getceil(tex, err, map) < 0 && map->okmap == 0)
		return (-1);
	free(map->file);
	map->file = NULL;
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
	else if (map->res == 0 || map->rx <= 0 || map->ry <= 0)
	{
		ft_printerr(err->err5);
		return (-5);
	}
	else if (map->rx > 2560 || map->ry > 1440)
	{
		map->rx = 2560; // CAMBIAR POR RESOLUCION MAXIMA
		map->ry = 1440; // CAMBIAR POR RESOLUCION MAXIMA
		return (0);
	}
	return (0);
}

int				ft_checkall(t_map *map, t_err *err)
{
	int		y;
	char	*str;

	str = NULL;
	while ((get_next_line(map->fd, &str)) > 0
		|| (get_next_line(map->fd, &str)) == EOF)
	{
		y = 0;
		map->lm++;
		while (str[y] != '\0')
		{
			if (str[y] == ' ' || str[y] == '1' || str[y] == '0' || str[y] == '2'
				|| str[y] == 'N' || str[y] == 'S' || str[y] == 'W'
				|| str[y] == 'E' || str[y] == '\t')
				y++;
			else
			{
				free(str);
				ft_printerr(err->err18);
				return (-18);
			}
		}
		free(str);
	}
	return (0);
}
