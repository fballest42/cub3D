/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:15:12 by fballest          #+#    #+#             */
/*   Updated: 2021/01/07 11:06:17 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_freemap(t_map *map)
{
	int		x;

	x = 0;
	while (map->mapa[x] != NULL)
	{
		free(map->mapa[x]);
		map->mapa[x] = NULL;
		x++;
	}
	free(map->mapa);
	map->mapa = NULL;
}

void		ft_freearray(char **fra)
{
	int		x;

	x = 0;
	while (fra[x] != NULL)
	{
		free(fra[x]);
		fra[x] = NULL;
		x++;
	}
	free(fra[x]);
	fra[x] = NULL;
	free(fra);
	fra = NULL;
}

void		ft_delerr(t_err *err)
{
	err->err1 = NULL;
	err->err2 = NULL;
	err->err3 = NULL;
	err->err4 = NULL;
	err->err5 = NULL;
	err->err6 = NULL;
	err->err7 = NULL;
	err->err8 = NULL;
	err->err9 = NULL;
	err->err10 = NULL;
	err->err11 = NULL;
	err->err12 = NULL;
	err->err13 = NULL;
	err->err14 = NULL;
	err->err15 = NULL;
	err->err16 = NULL;
	err->err17 = NULL;
	err->err18 = NULL;
	err->err19 = NULL;
	err->err20 = NULL;
	err->err21 = NULL;
	err->err22 = NULL;
	err->err23 = NULL;
	err->x = 0;
	err->ok = 0;
}

int			ft_checktexture(char *str, t_err *err)
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

void		ft_printerr(char *str)
{
	write(1, str, ft_strlenb(str));
}
