/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:17:25 by fballest          #+#    #+#             */
/*   Updated: 2020/11/04 11:08:15 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_extfile(char *str)
{
	int		i;
	int		j;
	char	*ext;

	i = 0;
	j = 0;
	ext = (char *)malloc(sizeof(char) * 7);
	while (str[i] != '\0')
	{
		if (str[i] == '.' && str[i + 1] != '/')
		{
			while (str[i] != '\0')
			{
				ext[j++] = str[i++];
			}
		}
		i++;
	}
	ext[i] = '\0';
	str = ext;
	free(ext);
	return (str);
}

int			ft_checkarg2(char **argv, t_map *map, t_err *err)
{
	char		*str;

	str = ft_extfile(argv[1]);
	if ((ft_strncmpb(str, ".cub", 4)) == 0 && (ft_strlenb(str) == 4))
	{
		if (argv[2] && (ft_strlenb(argv[2]) == 6)
			&& (ft_strncmpb(argv[2], "--save", 6)) == 0)
		{
			map->save = 1;
			return (1);
		}
		else if (!argv[2])
			return (1);
		else if (argv[2] && ((ft_strlenb(argv[2]) != 6)
			|| (ft_strncmpb(argv[2], "--save", 6) != 0)))
		{
			ft_printerr(err->err3);
			return (-3);
		}
	}
	else if ((ft_strncmpb(str, ".cub", 4)) != 0	|| (ft_strlenb(str) != 4))
	{
		ft_printerr(err->err2);
		return (-2);
	}
	return (1);
}

int			ft_checkarg(int argc, char **argv, t_map *map, t_err *err)
{
	if (argc == 2 || argc == 3)
	{
		if (ft_checkarg2(argv, map, err) == 1)
			return (1);
	}
	else
	{
		ft_printerr(err->err1);
		return (-1);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_map		*map;
	t_err		*err;
	t_tex		*tex;

	if (!(map = malloc(sizeof(t_map)))
		|| !(err = malloc(sizeof(t_err)))
		|| !(tex = malloc(sizeof(t_tex)))
		|| !(ft_init(map, tex, err)))
		return (-1);
	if (ft_checkarg(argc, argv, map, err) == 1)
	{
		if (ft_checker(map, err, tex, argv) == 0)
			ft_cubemain(map, err, tex);
		else
			return (-1);
	}
	else
		return (-1);
	ft_freemem(map, tex, err);
	return (0);
}
