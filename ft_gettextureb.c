/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettextureb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:37:59 by fballest          #+#    #+#             */
/*   Updated: 2020/10/14 12:54:55 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_getsprite(int x, t_tex *tex, t_err *err, t_map *map)
{
	int				y;
	int				i;

	y = 0;
	i = 0;
	y = ft_outspace(y, map->file[x]);
	if (map->file[x][y] == 'S' && map->file[x][y + 1] != 'O')
	{
		y = y + 1;
		tex->sp = tex->sp + 1;
		y = ft_outspace(y, map->file[x]);
		i = y;
		while (map->file[x][i] != '\0')
			i++;
		if (!(tex->rutasp = malloc(i + 1)))
			return (-1);
		i = 0;
		while (map->file[x][y] != 0)
			tex->rutasp[i++] = map->file[x][y++];
		tex->rutasp[i] = '\0';
		if (tex->rutasp == NULL)
		{
			ft_printerr(err->err9);
			return (-9);
		}
	}
	return (tex->sp);
}

int			ft_getceil(int x, t_tex *tex, t_err *err, t_map *map)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	y = ft_outspace(y, map->file[x]);
	if (map->file[x][y++] == 'C')
	{
		tex->ce = tex->ce + 1;
		while (map->file[x][y] != '\0' && i < 4)
		{
			y = ft_outspace(y, map->file[x]);
			tex->cei[i++] = ft_getceilb(y, x, map, err);
			while (map->file[x][y] && map->file[x][y] != ',')
				y++;
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

int			ft_getceilb(int y, int x, t_map *map, t_err *err)
{
	int		i;

	i = 0;
	while (map->file[x][y] >= '0' && map->file[x][y] <= '9')
	{
		i = i * 10 + (map->file[x][y] - 48);
		y++;
	}
	if (i < 0 || i > 255)
	{
		ft_printerr(err->err13);
		return (-13);
	}
	return (i);
}

int			ft_getflo(int x, t_tex *tex, t_err *err, t_map *map)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	y = ft_outspace(y, map->file[x]);
	if (map->file[x][y++] == 'F')
	{
		tex->fl = tex->fl + 1;
		while (map->file[x][y] != '\0' && i < 4)
		{
			y = ft_outspace(y, map->file[x]);
			tex->flo[i++] = ft_getceilb(y, x, map, err);
			while (map->file[x][y] && map->file[x][y] != ',')
				y++;
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
