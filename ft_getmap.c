/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2020/11/03 00:54:22 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(t_map *map, t_err *err)
{
	if (!map->mapa)
	{
		map->lm = map->fm - map->im;
		map->im = 0;
		map->mapa = (char **)malloc(sizeof(char *) * (map->lm + 1));
		map->mapa[map->lm + 1] = NULL;
	}
	if (map->im < (map->lm + 1))
		map->mapa[map->im] = ft_strdupb(map->file);
	if (ft_checkplayer(map, err) < 0)
		return (-1);
	if (map->im == (map->lm + 1))
		if (ft_checkmap(map, err) < 0)
			return (-1);
	return (0);
}

int				ft_checkmap(t_map *map, t_err *err)
{
	int		x;
	int		y;
	char	**val;

	x = 0;
	y = map->py;
	val = (char **)malloc(sizeof(char *) * (map->lm + 1));
	val[map->lm + 1] = NULL;
	while (map->mapa[x] != NULL)
	{
		val[x] = ft_strdupb(map->mapa[x]);
		x++;
	}
	err->x = x;
	x = map->px;
	return (ft_checkmap2(x, y, val, err));
}

int				ft_checkmap2(int x, int y, char **val, t_err *err)
{
	if (x == 0 || y == 0 || y == ft_strlenb(val[x]) || x == err->x - 1
		|| y > ft_strlenb(val[x + 1]))
	{
		ft_printerr(err->err15);
		return (-15);
	}
	val[x][y] = '3';
	if (val[x][y + 1] == '0' || val[x][y + 1] == ' ' || val[x][y + 1] == ' ')
		ft_checkmap2(x, y, val, err);
	if (val[x][y - 1] == '0' || val[x][y - 1] == ' ' || val[x][y - 1] == ' ')
		ft_checkmap2(x, y, val, err);
	if (val[x + 1][y] == '0' || val[x + 1][y] == ' ' || val[x + 1][y] == ' ')
		ft_checkmap2(x, y, val, err);
	if (val[x - 1][y] == '0' || val[x - 1][y] == ' ' || val[x - 1][y] == ' ')
		ft_checkmap2(x, y, val, err);
	if (val[x - 1][y + 1] == '0' || val[x - 1][y + 1] == ' ' || val[x - 1][y + 1] == ' ')
		ft_checkmap2(x, y, val, err);
	if (val[x + 1][y - 1] == '0' || val[x + 1][y - 1] == ' ' || val[x + 1][y - 1] == ' ')
		ft_checkmap2(x, y, val, err);
	if (val[x + 1][y + 1] == '0' || val[x + 1][y + 1] == ' ' || val[x + 1][y + 1] == ' ')
		ft_checkmap2(x, y, val, err);
	if (val[x - 1][y - 1] == '0' || val[x - 1][y - 1] == ' ' || val[x - 1][y - 1] == ' ')
		ft_checkmap2(x, y, val, err);
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

int				ft_checkplayer(t_map *map, t_err *err)
{
	int		y;

	y = 0;
	if (map->file[y] == 'N' || map->file[y] == 'S'
		|| map->file[y] == 'W' || map->file[y] == 'E')
	{
		map->px = map->im;
		map->py = y;
		map->pla = map->pla + 1;
	}
	if (map->pla > 1)
	{
		while (map->im >= 0)
			free (map->mapa[map->im--]);
		free(map->mapa);
		ft_printerr(err->err16);
		return (-16);
	}
	return (0);
}
