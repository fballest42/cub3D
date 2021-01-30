/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfileb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:55:23 by fballest          #+#    #+#             */
/*   Updated: 2021/01/30 12:06:51 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_outemptylines(t_map *map)
{
	int		y;

	y = 0;
	if (map->file[y] == 0 && map->okmap == 0)
	{
		free(map->file);
		map->file = NULL;
		return (-1);
	}
	return (1);
}

int				ft_getdatafileb(t_map *map, t_tex *tex, t_err *err)
{
	ft_checkduplicates(map, tex, err);
	if (map->res == 1 && tex->ce == 1 && tex->fl == 1 && tex->no == 1
		&& tex->so == 1 && tex->we == 1 && tex->ea == 1 && tex->sp == 1
		&& map->okmap == 1)
	{
		if ((ft_checkall(map, err) < 0) && map->okmap == 1)
			return (-1);
		if ((ft_getmap(map, err) < 0) && map->okmap == 1)
			return (-1);
	}
	else if (ft_getres(map, err) < 0)
		return (-1);
	else if (ft_gettex(tex, err, map) < 0)
		return (-1);
	else if (ft_getsprite(tex, err, map) < 0)
		return (-1);
	else if (ft_getceil(tex, err, map) < 0)
		return (-1);
	else if (ft_getflo(tex, err, map) < 0)
		return (-1);
	free(map->file);
	map->file = NULL;
	return (0);
}

void			ft_checkduplicates(t_map *map, t_tex *tex, t_err *err)
{
	if (map->res == 1 && tex->ce == 1 && tex->fl == 1 && tex->no == 1
		&& tex->so == 1 && tex->we == 1 && tex->ea == 1 && tex->sp == 1
		&& map->okmap == 0)
	{
		ft_getres(map, err);
		ft_gettex(tex, err, map);
		ft_getsprite(tex, err, map);
		ft_getceil(tex, err, map);
		ft_getflo(tex, err, map);
		map->okmap = 1;
	}
	if (map->res > 1 || tex->ce > 1 || tex->fl > 1 || tex->no > 1
		|| tex->so > 1 || tex->we > 1 || tex->ea > 1 || tex->sp > 1)
	{
		ft_printerr(err->err14);
		exit(-14);
	}
}

int				ft_checkokmap(t_map *map, t_tex *tex, t_err *err)
{
	if (map->okmap == 1 && (map->res == 0 || tex->ce == 0 || tex->fl == 0
		|| tex->no == 0 || tex->so == 0 || tex->we == 0 || tex->ea == 0
		|| tex->sp == 0))
	{
		ft_printerr(err->err17);
		exit(-17);
	}
	if (map->okmap == 0)
	{
		ft_printerr(err->err15);
		exit(-15);
	}
	return (0);
}

int				ft_openfileb(char *str, t_err *err)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) <= 0)
	{
		close(fd);
		ft_printerr(err->err19);
		exit(-19);
	}
	return (fd);
}
