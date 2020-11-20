/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:15:12 by fballest          #+#    #+#             */
/*   Updated: 2020/11/20 13:11:54 by fballest         ###   ########.fr       */
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
