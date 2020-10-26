/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/26 09:40:49 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(int x, t_map *map, t_err *err)
{
	int		y;

	y = 0;
	if (!(map->mapa = (char **)malloc(sizeof(char*) * map->i + 1)))
		return (-1);
	map->mapa[map->i] = ft_strdupb(map->file[x]);
	while (map->file[x][y] != '\0')
	{
		if (map->file[x][y] == ' ' || map->file[x][y] == '0'
			|| map->file[x][y] == '1' || map->file[x][y] == '2'
			|| map->file[x][y] == 'N' || map->file[x][y] == 'S'
			|| map->file[x][y] == 'W' || map->file[x][y] == 'E')
		{
			if (map->file[x][y] == 'N' || map->file[x][y] == 'S'
				|| map->file[x][y] == 'W' || map->file[x][y] == 'E')
			{
				map->px = x;
				map->py = y;
				map->pla = map->pla + 1;
				if (map->pla > 1)
				{
					ft_printerr(err->err16);
					return (-16);
				}
			}
			map->file[x][y] = map->mapa[map->i][y];
			y++;
		}
		else
		{
			ft_printerr(err->err15);
			return (-15);
		}
	}
	return (0);
}

int				ft_checkmap(t_map *map, t_err *err, t_tex *tex)
{
	printf("%s\n%s%s%s", "Leyendo y analizando el mapa", map->file[0], err->err24, tex->rutano);
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
