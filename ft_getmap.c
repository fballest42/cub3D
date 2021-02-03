/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:54:48 by fballest          #+#    #+#             */
/*   Updated: 2021/02/02 11:47:32 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_getmap(t_map *map, t_err *err)
{
	if (!map->mapa)
	{
		map->okmap = 1;
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
	ft_spritearray(map);
	ft_freearray(val);
	map->okmap = 1;
	return (0);
}

void			ft_spritearray(t_map *map)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	map->sprpos = (int **)malloc(sizeof(int *) * map->sprnum + 1);
	while (i <= map->sprnum)
		map->sprpos[i++] = (int *)malloc(sizeof(int) * 3);
	i = 0;
	while (map->mapa[x])
	{
		y = 0;
		while (map->mapa[x][y])
		{
			if (map->mapa[x][y] == '2')
			{
				map->sprpos[i][0] = x;
				map->sprpos[i++][1] = y;
			}
			y++;
		}
		x++;
	}
}

void			ft_checkmap2(int x, int y, char **str, t_err *err)
{
	if (x == 0 || y == 0 || y == (ft_strlenb(str[x]) - 1) || x == err->x - 1
		|| y >= ft_strlenb(str[x + 1]) || y >= ft_strlenb(str[x - 1]))
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
		exit(-4);
	}
	return (fd);
}
