/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/11/25 14:07:19 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_err *err, t_tex *tex)
{
	char	*raycast;
	void	*mlx_ptr;
	void	*mlx_win;

	if (!(raycast = malloc(sizeof(t_raycast))))
		return (-1);
	tex->rutano = err->err6;
	mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx_ptr, &map->grx, &map->gry);
	ft_getdefres(map);
	printf("\n%d\n%d\n", map->rx, map->ry);
	mlx_win = mlx_new_window(mlx_ptr, map->rx, map->ry, map->name);
	mlx_loop(mlx_ptr);
	return (0);
}

void			ft_getdefres(t_map *map)
{
	if (map->rx == 2560 && map->ry == 1440)
	{
		map->rx = map->grx;
		map->ry = map->gry;
	}
}
