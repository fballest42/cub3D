/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2020/11/08 17:57:58 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(t_map *map, t_err *err)
{
	if (!map->mapa)
	{
		map->lm = map->fm - (map->im - 1);
		err->x = map->lm;
		map->im = 0;
		map->mapa = (char **)malloc(sizeof(char *) * (map->lm + 1));
		map->mapa[map->lm] = NULL;
	}
	if (map->im <= map->lm)
		map->mapa[map->im] = ft_strdupb(map->file);
	if (ft_checkplayer(map->im, map, err) < 0)
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
	val[map->lm] = NULL;
	while (map->mapa[x] != NULL)
	{
		val[x] = ft_strdupb(map->mapa[x]);
		x++;
	}
	x = map->px;
	ft_checkmap2(x, y, val, err);
	ft_freearray(val);
	return (0);
}

void				ft_checkmap2(int x, int y, char **str, t_err *err)
{
	if (x == 0 || y == 0 || y == (ft_strlenb(str[x]))
	|| x == err->x - 1 || y > ft_strlenb(str[x + 1]) || y > ft_strlenb(str[x - 1]))
	{
		ft_freearray(str);
		ft_printerr(err->err15);
		exit(-15);
	}
	str[x][y] = '3';
	if (str[x][y + 1] == 48 || str[x][y + 1] == 50 || str[x][y + 1] == 32)
		ft_checkmap2(x, y + 1, str, err);
	if (str[x][y - 1] == 48 || str[x][y - 1] == 50 || str[x][y - 1] == 32)
		ft_checkmap2(x, y - 1, str, err);
	if (str[x + 1][y] == 48 || str[x + 1][y] == 50 || str[x + 1][y] == 32)
		ft_checkmap2(x + 1, y, str, err);
	if (str[x - 1][y] == 48 || str[x - 1][y] == 50 || str[x - 1][y] == 32)
		ft_checkmap2(x - 1, y, str, err);
}

int				ft_openfile(char *str, t_err *err)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) <= 0)
	{
		close(fd);
		ft_printerr(err->err4);
		exit (-4);
	}
	return (fd);
}

int				ft_openfileb(char *str, t_err *err)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) <= 0)
	{
		close(fd);
		ft_printerr(err->err19);
		return (-19);
	}
	return (fd);
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
		return (-16);
	}
	return (0);
}
