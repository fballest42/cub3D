/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/29 12:09:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(t_map *map, t_err *err, t_tex *tex)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (!(map->mapa = (char **)malloc(sizeof(char *) * map->lm + 1)))
		return (-1);
	map->mapa[x] = ft_strdupb(map->file);
	while (map->lm >= 0)
	{
		y = 0;
		while (map->file[y] != '\0')
		{
			map->mapa[x][y] = map->file[y];
			if (ft_checkplayer(x, y, map, err) < 0)
			{
				while (x <= 0)
					free (map->mapa[x--]);
				free(map->mapa);
			}
			y++;
		}
		x++;
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

int				ft_checkplayer(int x, int y, t_map *map, t_err *err)
{
	if (map->file[y] == 'N' || map->file[y] == 'S'
		|| map->file[y] == 'W' || map->file[y] == 'E')
	{
		map->px = x;
		map->py = y;
		map->pla = map->pla + 1;
	}
	if (map->pla > 1)
	{
		while (x <= 0)
			free (map->mapa[x--]);
		free(map->mapa);
		ft_printerr(err->err16);
		return (-16);
	}
	return (0);
}
