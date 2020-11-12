/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettextureb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:37:59 by fballest          #+#    #+#             */
/*   Updated: 2020/11/12 22:31:06 by fballest         ###   ########.fr       */
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
			ft_printerr(err->err6);
			exit(-6);
		}
	}
	return (tex->sp);
}

int			ft_getceil(t_tex *tex, t_err *err, t_map *map)
{
	int		i;

	i = 1;
	map->i = 0;
	ft_checknumbers(map, err);
	map->i = ft_outspace(map->i, map->file);
	if (map->file[map->i] == 'F')
	{
		map->i++;
		tex->ce = tex->ce + 1;
		while (map->file[map->i] != '\0' && i <= 4)
		{
			map->i = ft_outspace(map->i, map->file);
			tex->cei[i] = ft_getceilb(map, err);
			i++;
			map->i = ft_outspace(map->i, map->file);
			if (i == 4 && map->file[map->i] == '\0')
				return (0);
			ft_countcomas(map, err);
		}
	}
	return (0);
}

int			ft_getceilb(t_map *map, t_err *err)
{
	int		i;

	i = 0;
	map->i = ft_outspace(map->i, map->file);
	while (map->file[map->i] >= '0' && map->file[map->i] <= '9')
	{
		i = i * 10 + (map->file[map->i] - 48);
		map->i++;
	}
	if (i < 0 || i > 255)
	{
		ft_printerr(err->err13);
		exit(-13);
	}
	return (i);
}

int			ft_getflo(t_tex *tex, t_err *err, t_map *map)
{
	int		i;

	i = 1;
	map->i = 0;
	ft_checknumbers(map, err);
	map->i = ft_outspace(map->i, map->file);
	if (map->file[map->i] == 'F')
	{
		map->i++;
		tex->fl = tex->fl + 1;
		while (map->file[map->i] != '\0' && i <= 4)
		{
			map->i = ft_outspace(map->i, map->file);
			tex->flo[i] = ft_getceilb(map, err);
			i++;
			map->i = ft_outspace(map->i, map->file);
			if (i == 4 && map->file[map->i] == '\0')
				return (0);
			ft_countcomas(map, err);
		}
	}
	return (0);
}

void			ft_countlines(char *argv, t_map *map, t_err *err)
{
	int		y;
	int		fd;
	char	*cont;

	cont = NULL;
	fd = ft_openfile(argv, err);
	y = 0;
	while ((get_next_line(fd, &cont)) > 0)
	{
		map->fm++;
		free(cont);
		cont = NULL;
	}
	free(cont);
	cont = NULL;
	map->fm++;
	close(fd);
}

void			ft_checknumbers(t_map *map, t_err *err)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	y = ft_outspace(y, map->file);
	if (map->file[y] == 'F' || map->file[y] == 'C' || map->file[y] == 'R')
	{
		i = y;
		y++;
		while (map->file[y] && ((map->file[y] >= '0'
			&& map->file[y] <= '9') || map->file[y] == '\t'
			|| map->file[y] == ' ' || ((map->file[i] == 'F'
			|| map->file[i] == 'C') && map->file[y] == ',')))
			y++;
		if (map->file[y])
		{
			ft_printerr(err->err7);
			exit(-7);
		}
	}
}

void				ft_countcomas(t_map *map, t_err *err)
{
	if (map->file[map->i] == ',' && map->file[map->i + 1])
		map->i++;
	else
	{
		ft_printerr(err->err8);
		exit(-8);
	}
}
