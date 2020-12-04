/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/12/04 09:43:43 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_err *err, t_tex *tex)
{
	tex->rutano = err->err6;//OJO ELIMINAR SOLO HABILITADO PARA PASAR TEX
	map->mlx_ptr = mlx_init();
	ft_getdefres(map, tex);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->rx, map->ry, map->name);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->rx, map->ry);
	map->mlx_imgaddr = mlx_get_data_addr(map->mlx_img, &map->mlx_bxp,
		&map->mlx_sili, &map->mlx_endian);
	mlx_key_hook(map->mlx_win, ft_key_hook, map);
	mlx_loop_hook(map->mlx_ptr, ft_raycasting, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}

void			ft_getdefres(t_map *map, t_tex *tex)
{
	mlx_get_screen_size(map->mlx_ptr, &map->grx, &map->gry);
	if (map->rx == 2560 && map->ry == 1440)
	{
		map->rx = map->grx;
		map->ry = map->gry;
	}
	map->cei = ft_rgbtoint(tex->cei);
	map->flo = ft_rgbtoint(tex->flo);
}

void			ft_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->mlx_imgaddr + (y * map->mlx_sili + x * (map->mlx_bxp / 8));
	*(unsigned int *)dst = color;
}

int			ft_raycasting(t_map *map)
{
	ft_paint_cei_flo(map, 0, 0);
	return (0);
}

void			ft_paint_cei_flo(t_map *map, int x, int y)
{
	while (x < map->rx)
	{
		y = 0;
		while (y < map->ry)
		{
			if (y < (map->ry / 2))
				ft_mlx_pixel_put(map, x, y, map->cei);
			else if (y >= (map->ry / 2))
				ft_mlx_pixel_put(map, x, y, map->flo);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
}

int				ft_key_hook(int keycode, t_map *map)
{
	mlx_hook(map->mlx_win, 17, 1L << 17, ft_exit_game, map);
	//mlx_hook(map->mlx_win, 2, 1L << 0, ft_keypress, map);
	//mlx_hook(map->mlx_win, 3, 1L << 1, ft_keyrelease, map);
	if (keycode == A_KEY)
		printf("%s\n", "down");
	else if (keycode == W_KEY)
		printf("%s\n", "up");
	else if (keycode == S_KEY)
		printf("%s\n", "left");
	else if (keycode == D_KEY)
		printf("%s\n", "right");
	else if (keycode == ESC_KEY)
		ft_exit_game(map);
	else if (keycode == LEFT_KEY)
		printf("%s\n", "rotate left");
	else if (keycode == RIGHT_KEY)
		printf("%s\n", "rotate right");
	else if (keycode == X_BTN)
		printf("%s\n", "???");
	else if (keycode == LEFT_SHIFT)
		printf("%s\n", "faster");
	map->rx = map->rx + (1 * 0);
	return (0);
}

int				ft_exit_game(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	map->mlx_ptr = NULL;
	free(map->mlx_ptr);
	free(map->mlx_img);
	exit(0);
	return (0);
}
