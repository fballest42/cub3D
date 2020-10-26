/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:34:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 09:32:21 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

/*LIBRERIAS DE TRABJO*/

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

/*KEY DEFINITION AND LIBRARY ACCORDING TO OPERATIVE SYSTEM*/

# ifdef __APPLE__
#  include "mlx_ios/mlx.h"
#  define A_KEY 0
#  define W_KEY 13
#  define S_KEY 1
#  define D_KEY 2
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define ESC_KEY 53
#  define LEFT_SHIFT 257
#  define X_BTN 17

# elif defined __unix__
#  include "mlx_linux/mlx.h"
#  define A_KEY 97
#  define W_KEY 119
#  define S_KEY 115
#  define D_KEY 100
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define ESC_KEY 65307
#  define LEFT_SHIFT 65505
#  define X_BTN 33
# endif

/*WORK STRUCTS: T_MAP = MAP DATA, T_TEXT = TEXTURE DATA, T_VAR = VARIABLES*, T_ERROR = ERRORS*/

typedef struct	s_map
{
	int					i;
	int					res;
	int					rx;
	int					ry;
	char				*name;
	char				**tmp;
	char				**file;
	char				**mapa;
	int					okmap;
	char				**error;
	int					save;
	char				**savmap;
}				t_map;

typedef struct	s_tex
{
	int					no;
	char				*rutano;
	int					so;
	char				*rutaso;
	int					we;
	char				*rutawe;
	int					ea;
	char				*rutaea;
	int					sp;
	char				*rutasp;
	int					flo[4];
	int					fl;
	char				*rutafl;
	int					cei[4];
	int					ce;
	char				*rutace;
}				t_tex;

typedef struct	s_bar
{
	int					x;
	int					y;
	char				c;
	char				*str;
	char				**line;
}				t_bar;

typedef struct	s_err
{
	int			i;
	char		*err1;
	char		*err2;
	char		*err3;
	char		*err4;
	char		*err5;
	char		*err6;
	char		*err7;
	char		*err8;
	char		*err9;
	char		*err10;
	char		*err11;
	char		*err12;
	char		*err13;
	char		*err14;
	char		*err15;
	char		*err16;
	char		*err17;
	char		*err18;
	char		*err19;
	char		*err20;
	char		*err21;
	char		*err22;
	char		*err23;
	char		*err24;
}				t_err;

/*LIST OF FUNTIONS AND FILES WHERE YOU CAN FIND EACH FUNTION*/

/* FILES IN CUB3D.c*/
int				ft_checkarg(int argc, char **argv, t_map *map, t_err *err);
int				ft_checkarg2(char **argv, t_map *map, t_err *err);
char			*ft_extfile(char *str);

/*FILES IN FT_READFILE.C*/
int				ft_checker(t_map *map, t_err *err, t_tex *tex, char **argv);
int				ft_getdatafile(t_map *map, t_err *err, t_tex *tex);
void			ft_getres(t_map *map);
int				ft_checkres(t_map *map, t_err *err);
int				ft_checkall(t_map *map, t_tex *tex);

/*FILES IN FT_GETTEXTURE.C*/
void			ft_gettex(int y, t_tex *tex, t_err *err, t_map *map);
int				ft_gettexno(int y, t_tex *tex, t_err *err, t_map *map);
int				ft_gettexso(int y, t_tex *tex, t_err *err, t_map *map);
int 			ft_gettexwe(int y, t_tex *tex, t_err *err, t_map *map);
int				ft_gettexea(int y, t_tex *tex, t_err *err, t_map *map);

/*FILES IN FT_GETTEXTUREB.C*/
int				ft_getsprite(int i, t_tex *tex, t_err *err, t_map *map);
int				ft_getceilb(int y, t_map *map, t_err *err);
int				ft_getceil(int y, t_tex *tex, t_err *err, t_map *map);
int				ft_getflo(int y, t_tex *tex, t_err *err, t_map *map);

/*FILES IN FT_GETMAP.C*/
int				ft_getmap(int i, t_map *map, t_tex *tex);
int				ft_checkmap(t_map *map, t_err *err, t_tex *tex);

/*FILES IN FT_CUBEMAIN.C*/
int				ft_cubemain(t_map *map, t_err *err, t_tex *tex);

/*FILES IN FT_ERRORS.C*/
void			ft_inierr(t_err *err);
void			ft_printerr(char *str);

/*FILES IN FT_STRUTINIT.C*/
void			ft_inimap(t_map *map);
void			ft_initex(t_tex *tex);
void			ft_inibar(t_bar *bar);
int				ft_init(t_map *map, t_err *err, t_tex *tex, t_bar *bar);

/*FILES IN FT_UTILSA.C*/
int				ft_strncmpb(const char *s1, const char *s2, size_t n);
int				ft_strlenb(char *str);
char			*ft_strjoinb(char *str, char *s2);
char			*ft_strdupb(char *str);

/*FILES IN FT_UTILS.C*/
char			*ft_substrb(char *s, unsigned int start, size_t len);
char			*ft_strchrb(char *s, int c);
int				ft_outspace(int i, t_map *map);
int				ft_checkspace(t_map *map);

/* FUNCIONES QUE NO SE ESTAN USANDO NI ESTAN CREADAS
int				ft_initcreate(int i);
int				ft_checktex(t_map *map, t_err *err);
int				ft_checksprite(t_map *map, t_err *err);*/




#endif
