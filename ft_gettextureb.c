/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettextureb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:37:59 by fballest          #+#    #+#             */
/*   Updated: 2020/10/26 18:53:47 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_getsprite(t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	y = 0;
	i = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y] == 'S' && map->file[y + 1] != 'O')
	{
		y = y + 1;
		tex->sp = tex->sp + 1;
		y = ft_outspace(y, map->file);
		i = y;
		while (map->file[i] != '\0')
			i++;
		if (!(tex->rutasp = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[y] != 0)
			tex->rutasp[i++] = map->file[y++];
		tex->rutasp[i] = '\0';
		if (tex->rutasp == NULL)
		{
			ft_printerr(err->err9);
			return (-9);
		}
	}
	return (tex->sp);
}

int			ft_getceil(t_tex *tex, t_err *err, t_map *map)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y++] == 'C')
	{
		tex->ce = tex->ce + 1;
		while (map->file[y] != '\0' && i < 4)
		{
			y = ft_outspace(y, map->file);
			tex->cei[i++] = ft_getceilb(y, map, err);
			if (tex->cei[i] < 0 || tex->cei[i] > 255)
			{
				ft_printerr(err->err13);
				return (-13);
			}
			y++;
		}
		tex->cei[i] = '\0';
	}
	return (tex->ce);
}

int			ft_getceilb(int y, t_map *map, t_err *err)
{
	int		i;

	i = 0;
	y = ft_outspace(y, map->file);
	while (map->file[y] >= '0' && map->file[y] <= '9')
	{
		i = i * 10 + (map->file[y] - 48);
		y++;
	}
	if (i < 0 || i > 255)
	{
		ft_printerr(err->err13);
		return (-13);
	}
	return (i);
}

int			ft_getflo(t_tex *tex, t_err *err, t_map *map)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y++] == 'F')
	{
		tex->fl = tex->fl + 1;
		while (map->file[y] != '\0' && i < 4)
		{
			y = ft_outspace(y, map->file);
			tex->flo[i++] = ft_getceilb(y, map, err);
			if (tex->flo[i] < 0 || tex->flo[i] > 255)
			{
				ft_printerr(err->err13);
				return (-13);
			}
			y++;
		}
		tex->flo[i] = '\0';
	}
	return (tex->fl);
}
