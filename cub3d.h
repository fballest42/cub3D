/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:34:48 by fballest          #+#    #+#             */
/*   Updated: 2021/01/23 11:18:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

/*
**LIBRERIAS DE TRABAJO
*/
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

/*
**KEY DEFINITION AND LIBRARY ACCORDING TO OPERATIVE SYSTEM
*/
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
#  define MSPD 0.07
#  define RSPD 0.04363325
# elif defined __UNIX__
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

typedef struct	s_texrc
{
	void				*img;
	char				*addr;
	char				*ruttex;
	int					sizeli;
	int					bpptex;
	int					endian;
}				t_texrc;

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
	void				*mlx_ptr;
	void				*mlx_win;
	void				**mlx_img;
	char				*mlx_imgaddr;
	int					mlx_bxp;
	int					mlx_sili;
	int					mlx_endian;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	int					mapx;
	int					mapy;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					keyw;
	int					keys;
	int					keya;
	int					keyd;
	int					keyesc;
	int					keylft;
	int					keyrgh;
	double				olddirx;
	double				oldplanex;
	int					wcol;
	int					tex_id;
	int					texheight;
	int					texwidth;
	double				wallx;
	int					texx;
	int					texy;
	int					texside;
	double				step;
	double				texpos;
	int					sprnum;
	int					**sprpos;
	double				*sprite;
	int					*sprord;
	double				*sprdist;
	float				raydirx0;
	float				raydiry0;
	float				raydirx1;
	float				raydiry1;
	int					p;
	float				posz;
	float				rowdist;
	int					*neword;
	double				spritex;
	double				spritey;
	double				invdet;
	double				transformx;
	double				transformy;
	int					sprscreenx;
	int					sprheight;
	int					drawstarty;
	int					drawendy;
	int					sprwidth;
	int					drawstartx;
	int					drawendx;
	int					stripe;
	double				sprtexx;
	double				sprtexy;
	t_texrc				texrc[5];
}				t_map;

typedef struct		s_bmp
{
	int					fdsave;
	int					filesize;
	int					pixelsize;
	int					unused;
	int					offset_begin;
	int					header_bytes;
	short int			bmpplane;
	short int			bmpbxp;
}					t_bmp;

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

/*
**LIST OF FUNTIONS AND FILES WHERE YOU CAN FIND EACH FUNTION
*/

/*
**FILES IN CUB3D.C + MAIN
*/
int				ft_checkarg(int argc, char **argv, t_map *map, t_err *err);
int				ft_checkarg2(char **argv, t_map *map, t_err *err);
int				ft_checkarg3(char **argv, t_map *map, t_err *err);
char			*ft_extfile(char *str);

/*
**FILES IN FT_READFILE.C
*/
int				ft_checker(t_map *map, t_err *err, t_tex *tex, char **argv);
int				ft_getdatafile(t_map *map, t_err *err, t_tex *tex);
int				ft_getres(t_map *map, t_err *err);
int				ft_checkres(t_map *map, t_err *err);
int				ft_checkall(t_map *map, t_err *err);

/*
**FILES IN FT_READFILEB.C
*/
int				ft_outemptylines(t_map *map);
int				ft_getdatafileb(t_map *map, t_tex *tex, t_err *err);
void			ft_checkduplicates(t_map *map, t_tex *tex, t_err *err);
int				ft_checkokmap(t_map *map, t_tex *tex, t_err *err);
int				ft_openfileb(char *str, t_err *err);

/*
**FILES IN FT_GETTEXTURE.C
*/
int				ft_gettex(t_tex *tex, t_err *err, t_map *map);
int				ft_gettexno(t_tex *tex, t_err *err, t_map *map);
int				ft_gettexso(t_tex *tex, t_err *err, t_map *map);
int				ft_gettexwe(t_tex *tex, t_err *err, t_map *map);
int				ft_gettexea(t_tex *tex, t_err *err, t_map *map);

/*
**FILES IN FT_GETTEXTUREB.C
*/
int				ft_getsprite(t_tex *tex, t_err *err, t_map *map);
int				ft_getceilb(t_map *map, t_err *err);
int				ft_getceil(t_tex *tex, t_err *err, t_map *map);
int				ft_getflo(t_tex *tex, t_err *err, t_map *map);
void			ft_checknull(char *str, t_err *err);

/*
**FILES IN FT_GETTEXTUREC.C
*/
void			ft_checknumbers(t_map *map, t_err *err);
void			ft_countcomas(t_map *map, t_err *err);
void			ft_countlines(char *argv, t_map *map, t_err *err);
int				ft_checkplayer(int x, t_map *map, t_err *err);
void			ft_checkplayerb(t_map *map, int x, int y);

/*
**FILES IN FT_GETMAP.C
*/

int				ft_getmap(t_map *map, t_err *err);
int				ft_checkmap(t_map *map, t_err *err);
void			ft_checkmap2(int x, int y, char **str, t_err *err);
void			ft_spritearray(t_map *map);
int				ft_openfile(char *str, t_err *err);

/*
**FILES IN FT_FREEDOM.C
*/
void			ft_freemap(t_map *map);
void			ft_delerr(t_err *err);
void			ft_freearray(char **fra);
int				ft_checktexture(char *str, t_err *err);
void			ft_printerr(char *str);

/*
**FILES IN FT_STRUTINIT.C
*/
void			ft_inimap(t_map *map);
void			ft_initex(t_tex *tex);
int				ft_init(t_map *map, t_tex *tex, t_err *err);
void			ft_initmlx(t_map *map);
void			ft_initmlxb(t_map *map);

/*
**FILES IN FT_STRUTINITB.C
*/
void			ft_inierr(t_err *err);
void			ft_initmlxc(t_map *map);
void			ft_initmlxd(t_map *map);
void			ft_initmlxe(t_map *map);
int				ft_rgbtoint(int *hex);

/*
**FILES IN FT_UTILSA.C
*/
int				ft_strncmpb(const char *s1, const char *s2, size_t n);
int				ft_strlenb(char *str);
char			*ft_strjoinb(char *str, char *s2);
char			*ft_strdupb(char *str);
int				ft_freestruct(t_map *map, t_tex *tex);

/*
**FILES IN FT_UTILSB.C
*/
char			*ft_substrb(char *s, unsigned int start, size_t len);
char			*ft_strchrb(char *s, int c);
int				ft_outspace(int i, char *str);
int				ft_checkspace(t_map *map);
void			ft_freemem(t_map *map, t_tex *tex, t_err *err);

/*
**FILES IN FT_RAYCASTING.C
*/
int				ft_keypress(int key, t_map *map);
int				ft_keyrelease(int key, t_map *map);
int				ft_key_hook(t_map *map);
void			ft_key_hook2(t_map *map);
void			ft_key_hook3(t_map *map);

/*
**FILES IN FT_RAYCASTINGB.C
*/
void			ft_setinfo(int x, t_map *map);
void			ft_wallident(t_map *map);
void			ft_loadtex(t_map *map);
void			ft_mlx_pixel_put(t_map *map, int x, int y, int color);
int				ft_getpixel(t_map *map, int x, int y);

/*
**FILES IN FT_RAYCASTINGC.C
*/
void			ft_heightdraw(t_map *map);
void			ft_verline(int x, t_map *map);
void			ft_painttex(t_map *map);
void			ft_painttexb(t_map *map, int x, int y);
int				ft_exit_game(t_map *map);

/*
**FILES IN FT_RAYCASTINGD.C
*/
void			ft_raycastingb(t_map *map);
void			ft_paintspr(t_map *map);
void			ft_calculatespr(t_map *map, int i);
void			ft_sortsprites(t_map *map);
void			ft_sortspritesb(t_map *map);

/*
**FILES IN FT_RAYCASTINGE.C
*/
void			ft_getdefres(t_map *map, t_tex *tex);
void			ft_initialstep(t_map *map);
void			ft_hitwall(t_map *map);
void			ft_getinfo(t_map *map);

/*
**FILES IN FT_CUBEMAIN.C
*/
int				ft_cubemain(t_map *map, t_tex *tex);
int				ft_raycasting(t_map *map);
void			ft_copyimage(t_map *map);
void			ft_writebmp(t_map *map, t_bmp *bmp);
void			ft_initsave(t_map *map, t_bmp *bmp);
void			ft_writeheader(t_map *map, t_bmp *bmp);

#endif
