/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/30 13:58:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(t_map *map, t_err *err)
{
	int		y;

	y = 0;
	if (map->mapa)
	{
		map->tmp = map->mapa;
		map->lm++;
		ft_freearray(map->mapa);
	}
	if (!(map->mapa = (char **)malloc(sizeof(char *) * map->lm + 1)))
		return (-1);
	if (map->tmp)
	{
		while (map->tmp[y] != '\0')
		{
			map->mapa[y] = ft_strdupb(map->tmp[y]);
			y++;
		}
	}
	map->mapa[map->lm] = ft_strdupb(map->file);
	map->mapa[map->lm + 1] = NULL;
	if (ft_checkplayer(map->im, y, map, err) < 0)
		return (-1);
	return (0);
}

int				ft_checkmap(t_map *map, t_err *err)
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "Leyendo y analizando el mapa", map->mapa[0], map->mapa[1], map->mapa[2], map->mapa[3], map->mapa[4], err->err1);
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
