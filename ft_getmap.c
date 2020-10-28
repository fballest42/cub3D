/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/28 13:25:31 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(t_map *map, t_err *err, t_tex *tex)
{
	int		y;

	y = 0;
	if (map->mapa)
	{
		map->tmp = ft_split(*map->mapa, '\0');
		while (map->okmap <= 0)
			free(map->mapa[map->okmap--]);
		free(map->mapa);
	}
	map->mapa = ft_split(map->file, '\0');
	map->mapa[map->okmap] = ft_strdupb(map->file);
	map->mapa = map->tmp;
	while (map->file[y] != '\0')
	{
		map->mapa[map->okmap][y] = map->file[y];
		if (map->file[y] == 'N' || map->file[y] == 'S'
			|| map->file[y] == 'W' || map->file[y] == 'E')
		{
			map->px = map->okmap;
			map->py = y;
			map->pla = map->pla + 1;
			if (map->pla > 1)
			{
				ft_printerr(err->err16);
				return (-16);
			}
		}
		y++;
	}
	return (ft_checkmap(map, err, tex));
}

int				ft_checkmap(t_map *map, t_err *err, t_tex *tex)
{
	printf("%s\n%s%s%s", "Leyendo y analizando el mapa", map->file, err->err24, tex->rutano);
	return (0);
}

int				ft_openfile(char *str, t_err *err)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) < 0)
	{
		close(fd);
		ft_printerr(err->err4);
		return (-4);
	}
	return (fd);
}
