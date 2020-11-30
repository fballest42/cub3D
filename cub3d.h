/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:34:48 by fballest          #+#    #+#             */
/*   Updated: 2020/11/27 22:25:09 by fballest         ###   ########.fr       */
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

typedef struct	s_raycast
{
	int					i;
	int					res;
}				t_raycast;

typedef struct	s_map
{
	int					i;
	int					res;
	int					rx;
	int					ry;
	int					grx;
	int					gry;
	int					pla;
	int					px;
	int					py;
	int					fm;
	int					lm;
	int					im;
	char				por;
	int					cei;
	int					flo;
	char				*name;
	char				*file;
	char				**mapa;
	int					okmap;
	int					save;
	char				**savmap;
	void				*mlx_ptr;
	void				*mlx_win;
	void				**mlx_img;
	char				*mlx_imgaddr;
	int					*mlx_bxp;
	int					*mlx_sili;
	int					*mlx_endian;
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
	int			x;
	int			ok;
}				t_err;

/*LIST OF FUNTIONS AND FILES WHERE YOU CAN FIND EACH FUNTION*/

/* FILES IN CUB3D.c*/
int				ft_checkarg(int argc, char **argv, t_map *map, t_err *err);
int				ft_checkarg2(char **argv, t_map *map, t_err *err);
int				ft_checkarg3(char **argv, t_map *map, t_err *err);
char			*ft_extfile(char *str);

/*FILES IN FT_READFILE.C*/
int				ft_checker(t_map *map, t_err *err, t_tex *tex, char **argv);
int				ft_getdatafile(t_map *map, t_err *err, t_tex *tex);
int				ft_getres(t_map *map, t_err *err);
int				ft_checkres(t_map *map, t_err *err);
int				ft_checkall(t_map *map, t_err *err);

/*FILES IN FT_READFILEB.C*/
int				ft_outemptylines(t_map *map);
int				ft_getdatafileb(t_map *map, t_tex *tex, t_err *err);
void			ft_checkduplicates(t_map *map, t_tex *tex, t_err *err);
int				ft_checkokmap(t_map *map, t_tex *tex, t_err *err);

/*FILES IN FT_GETTEXTURE.C*/
int				ft_gettex(t_tex *tex, t_err *err, t_map *map);
int				ft_gettexno(t_tex *tex, t_err *err, t_map *map);
int				ft_gettexso(t_tex *tex, t_err *err, t_map *map);
int 			ft_gettexwe(t_tex *tex, t_err *err, t_map *map);
int				ft_gettexea(t_tex *tex, t_err *err, t_map *map);

/*FILES IN FT_GETTEXTUREB.C*/
int				ft_getsprite(t_tex *tex, t_err *err, t_map *map);
int				ft_getceilb(t_map *map, t_err *err);
int				ft_getceil(t_tex *tex, t_err *err, t_map *map);
int				ft_getflo(t_tex *tex, t_err *err, t_map *map);
void			ft_checknull(char *str, t_err *err);

/*FILES IN FT_GETTEXTUREC.C*/
void			ft_checknumbers(t_map *map, t_err *err);
void			ft_countcomas(t_map *map, t_err *err);
void			ft_countlines(char *argv, t_map *map, t_err *err);
int				ft_checkplayer(int x, t_map *map, t_err *err);
int				ft_checktexture(char *str, t_err *err);

/*FILES IN FT_GETMAP.C*/
int				ft_openfile(char *str, t_err *err);
int				ft_openfileb(char *str, t_err *err);
int				ft_getmap(t_map *map, t_err *err);
int				ft_checkmap(t_map *map, t_err *err);
void			ft_checkmap2(int x, int y, char **str, t_err *err);

/*FILES IN FT_FREEDOM.C*/
void			ft_freemap(t_map *map);
void			ft_delerr(t_err *err);
void			ft_freearray(char **fra);

/*FILES IN FT_STRUTINIT.C*/
void			ft_inimap(t_map *map);
void			ft_initex(t_tex *tex);
int				ft_init(t_map *map, t_tex *tex, t_err *err);
void			ft_inierr(t_err *err);
void			ft_initmlx(t_map *map);

/*FILES IN FT_UTILSA.C*/
int				ft_strncmpb(const char *s1, const char *s2, size_t n);
int				ft_strlenb(char *str);
char			*ft_strjoinb(char *str, char *s2);
char			*ft_strdupb(char *str);
int				ft_freestruct(t_map *map, t_tex *tex);

/*FILES IN FT_UTILSB.C*/
char			*ft_substrb(char *s, unsigned int start, size_t len);
char			*ft_strchrb(char *s, int c);
int				ft_outspace(int i, char *str);
int				ft_checkspace(t_map *map);
void			ft_freemem(t_map *map, t_tex *tex, t_err *err);

/*FILES IN FT_UTILSB.C*/
int         	ft_rgbtoint(int *hex);
void			ft_printerr(char *str);

/*FILES IN FT_CUBEMAIN.C*/
int				ft_cubemain(t_map *map, t_err *err, t_tex *tex);
void			ft_getdefres(t_map *map, t_tex *tex);
void			ft_mlx_pixel_put(t_map *map, int x, int y, int color);
void			ft_paint_cei_flo(t_map *map);

#endif
