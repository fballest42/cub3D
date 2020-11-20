/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettexturec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:01:08 by fballest          #+#    #+#             */
/*   Updated: 2020/11/20 13:05:24 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void			ft_countcomas(t_map *map, t_err *err)
{
	if (map->file[map->i] == ',' && map->file[map->i + 1])
		map->i++;
	else
	{
		ft_printerr(err->err8);
		exit(-8);
	}
}

int				ft_checkplayer(int x, t_map *map, t_err *err)
{
	int		y;

	y = 0;
	x = map->im;
	while (map->mapa[x][y] != '\0')
	{
		if (map->mapa[x][y] == 'N' || map->mapa[x][y] == 'S'
			|| map->mapa[x][y] == 'W' || map->mapa[x][y] == 'E')
		{
			map->px = map->im;
			map->py = y;
			map->pla = map->pla + 1;
		}
		y++;
	}
	if (map->pla > 1)
	{
		ft_printerr(err->err16);
		exit(-16);
	}
	return (0);
}

int				ft_checktexture(char *str, t_err *err)
{
	char		*ext;
	int			y;

	y = 0;
	ext = ft_extfile(str);
	y = ft_strlenb(ext);
	if (ft_strncmpb(ext, ".xpm", y) == 0)
		return (0);
	else
	{
		ft_printerr(err->err6);
		exit(-6);
	}
}
