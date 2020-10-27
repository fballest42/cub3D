/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/26 19:36:52 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(t_map *map, t_err *err)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	
	while (map->file[y] != '\0')
	{
		map->mapa = ft_split(map->file, '\0');
		map->mapa[x] = ft_strdupb(map->file);
		if (map->file[y] == ' ' || map->file[y] == '0'
			|| map->file[y] == '1' || map->file[y] == '2'
			|| map->file[y] == 'N' || map->file[y] == 'S'
			|| map->file[y] == 'W' || map->file[y] == 'E')
		{
			if (map->file[y] == 'N' || map->file[y] == 'S'
				|| map->file[y] == 'W' || map->file[y] == 'E')
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
			map->file[x] = map->mapa[map->i][y];
			x++;
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
