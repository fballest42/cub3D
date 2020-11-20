/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:41:39 by fballest          #+#    #+#             */
/*   Updated: 2020/11/20 13:05:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_gettex(t_tex *tex, t_err *err, t_map *map)
{
	int		i;

	i = 0;
	if (ft_gettexno(tex, err, map) < 0)
		return (-1);
	if (ft_gettexso(tex, err, map) < 0)
		return (-1);
	if (ft_gettexwe(tex, err, map) < 0)
		return (-1);
	if (ft_gettexea(tex, err, map) < 0)
		return (-1);
	if ((tex->rutano && (ft_openfileb(tex->rutano, err) <= 0)) || (tex->rutaso
		&& (ft_openfileb(tex->rutaso, err) <= 0)) || (tex->rutawe
		&& (ft_openfileb(tex->rutawe, err) <= 0)) || (tex->rutaea
		&& (ft_openfileb(tex->rutaea, err) <= 0)))
		return (-1);
	if ((tex->rutano && (ft_checktexture(tex->rutano, err) != 0))
		|| (tex->rutaso && (ft_checktexture(tex->rutaso, err) != 0))
		|| (tex->rutawe && (ft_checktexture(tex->rutawe, err) != 0))
		|| (tex->rutaea && (ft_checktexture(tex->rutaea, err) != 0)))
		return (-1);
	return (0);
}

int				ft_gettexno(t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y] == 'N' && map->file[y + 1] == 'O')
	{
		y = y + 2;
		tex->no = tex->no + 1;
		y = ft_outspace(y, map->file);
		i = y;
		while (map->file[i] != '\0')
			i++;
		if (!(tex->rutano = malloc(sizeof(char) * (i + 1))))
			return (-1);
		i = 0;
		while (map->file[y] != 0)
			tex->rutano[i++] = map->file[y++];
		tex->rutano[i] = '\0';
		if (tex->rutano == NULL)
		{
			ft_printerr(err->err6);
			exit(-6);
		}
	}
	return (tex->no);
}

int				ft_gettexso(t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y] == 'S' && map->file[y + 1] == 'O')
	{
		y = y + 2;
		tex->so = tex->so + 1;
		y = ft_outspace(y, map->file);
		i = y;
		while (map->file[i] != '\0')
			i++;
		if (!(tex->rutaso = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[y] != 0)
			tex->rutaso[i++] = map->file[y++];
		tex->rutaso[i] = '\0';
		if (tex->rutaso == NULL)
		{
			ft_printerr(err->err6);
			exit(-6);
		}
	}
	return (tex->so);
}

int				ft_gettexwe(t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y] == 'W' && map->file[y + 1] == 'E')
	{
		y = y + 2;
		tex->we = tex->we + 1;
		y = ft_outspace(y, map->file);
		i = y;
		while (map->file[i] != '\0')
			i++;
		if (!(tex->rutawe = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[y] != 0)
			tex->rutawe[i++] = map->file[y++];
		tex->rutawe[i] = '\0';
		if (tex->rutawe == NULL)
		{
			ft_printerr(err->err6);
			exit(-6);
		}
	}
	return (tex->we);
}

int				ft_gettexea(t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	i = 0;
	y = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y] == 'E' && map->file[y + 1] == 'A')
	{
		y = y + 2;
		tex->ea = tex->ea + 1;
		y = ft_outspace(y, map->file);
		i = y;
		while (map->file[i] != '\0')
			i++;
		if (!(tex->rutaea = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[y] != 0)
			tex->rutaea[i++] = map->file[y++];
		tex->rutaea[i] = '\0';
		if (tex->rutaea == NULL)
		{
			ft_printerr(err->err6);
			exit(-6);
		}
	}
	return (tex->ea);
}
