/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:42:00 by fballest          #+#    #+#             */
/*   Updated: 2021/01/30 10:42:39 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_writebmp(t_map *map, t_bmp *bmp)
{
	int		y;
	int		x;
	int		line;

	y = 0;
	while (y <= map->ry)
	{
		x = 0;
		line = (map->mlx_sili / 4) * (map->ry - y);
		while (x < map->rx)
		{
			write(bmp->fdsave, &map->mlx_imgaddr[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}

void			ft_freecopy(t_map *map, t_bmp *bmp)
{
	free(bmp);
	ft_inimap(map);
	map->name = NULL;
	ft_initmlx(map);
	free(map->sprite);
	free(map->sprord);
	free(map->sprdist);
	free(map);
	map->mlx_ptr = NULL;
	map->mlx_img = NULL;
	free(map->mlx_ptr);
}
