/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2021/01/07 11:33:59 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_tex *tex)
{
	ft_getdefres(map, tex);
	map->mlx_ptr = mlx_init();
	ft_loadtex(map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->rx, map->ry, map->name);
	mlx_hook(map->mlx_win, 17, 1L << 17, ft_exit_game, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, ft_keypress, map);
	mlx_hook(map->mlx_win, 3, 1L << 1, ft_keyrelease, map);
	mlx_loop_hook(map->mlx_ptr, ft_raycasting, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}

int				ft_raycasting(t_map *map)
{
	int			x;

	x = 0;
	ft_key_hook(map);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->rx, map->ry);
	map->mlx_imgaddr = mlx_get_data_addr(map->mlx_img, &map->mlx_bxp,
		&map->mlx_sili, &map->mlx_endian);
	while (x < map->rx)
	{
		ft_setinfo(x, map);
		ft_initialstep(map);
		ft_hitwall(map);
		ft_heightdraw(map);
		ft_painttex(map);
		ft_verline(x, map);
		x++;
	}
	ft_raycastingb(map);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
	ft_copyimage(map);
	mlx_destroy_image(map->mlx_ptr, map->mlx_img);
	return (0);
}

void			ft_copyimage(t_map *map)
{
	if (map->save == 1)
	{
		map->save++;
	}
}
