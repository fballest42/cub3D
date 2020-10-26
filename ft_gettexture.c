/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:41:39 by fballest          #+#    #+#             */
/*   Updated: 2020/10/19 08:48:43 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_gettex(int x, t_tex *tex, t_err *err, t_map *map)
{
	int		i;

	i = 0;
	if (tex->no == 0)
		i = ft_gettexno(x, tex, err, map);
	if (tex->so == 0)
		i = ft_gettexso(x, tex, err, map);
	if (tex->we == 0)
		i = ft_gettexwe(x, tex, err, map);
	if (tex->ea == 0)
		i = ft_gettexea(x, tex, err, map);
	return (i);
}

int				ft_gettexno(int x, t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file[x]);
	if (map->file[x][y] == 'N' && map->file[x][y + 1] == 'O')
	{
		y = y + 2;
		tex->no = tex->no + 1;
		y = ft_outspace(y, map->file[x]);
		i = y;
		while (map->file[x][i] != '\0')
			i++;
		if (!(tex->rutano = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[x][y] != 0)
			tex->rutano[i++] = map->file[x][y++];
		tex->rutano[i] = '\0';
		if (tex->rutano == NULL)
		{
			ft_printerr(err->err6);
			return (-6);
		}
	}
	return (tex->no);
}

int				ft_gettexso(int x, t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file[x]);
	if (map->file[x][y] == 'S' && map->file[x][y + 1] == 'O')
	{
		y = y + 2;
		tex->so = tex->so + 1;
		y = ft_outspace(y, map->file[x]);
		i = y;
		while (map->file[x][i] != '\0')
			i++;
		if (!(tex->rutaso = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[x][y] != 0)
			tex->rutaso[i++] = map->file[x][y++];
		tex->rutaso[i] = '\0';
		if (tex->rutaso == NULL)
		{
			ft_printerr(err->err7);
			return (-7);
		}
	}
	return (tex->so);
}

int				ft_gettexwe(int x, t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file[x]);
	if (map->file[x][y] == 'W' && map->file[x][y + 1] == 'E')
	{
		y = y + 2;
		tex->we = tex->we + 1;
		y = ft_outspace(y, map->file[x]);
		i = y;
		while (map->file[x][i] != '\0')
			i++;
		if (!(tex->rutawe = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[x][y] != 0)
			tex->rutawe[i++] = map->file[x][y++];
		tex->rutawe[i] = '\0';
		if (tex->rutawe == NULL)
		{
			ft_printerr(err->err8);
			return (-8);
		}
	}
	return (tex->we);
}

int				ft_gettexea(int x, t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file[x]);
	if (map->file[x][y] == 'E' && map->file[x][y + 1] == 'A')
	{
		y = y + 2;
		tex->ea = tex->ea + 1;
		y = ft_outspace(y, map->file[x]);
		i = y;
		while (map->file[x][i] != '\0')
			i++;
		if (!(tex->rutaea = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[x][y] != 0)
			tex->rutaea[i++] = map->file[x][y++];
		tex->rutaea[i] = '\0';
		if (tex->rutaea == NULL)
		{
			ft_printerr(err->err9);
			return (-9);
		}
	}
	return (tex->ea);
}
