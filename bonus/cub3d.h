/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 22:12:09 by jcluzet           #+#    #+#             */
/*   Updated: 2021/02/11 18:52:44 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# if defined(__APPLE__) && defined(__MACH__)
#  define ADVANCE 13
#  define BACK 1
#  define RIGHT 2
#  define LEFT 0
#  define ROT_RIGHT 124
#  define ROT_LEFT 123
#  define ESC 53
#  define RED_BUTTON 79
#  define LIGHTS 29
#  define OPEN_DOOR 25
#  define CLOSERED 17
# else
#  define ADVANCE 119
#  define BACK 115
#  define RIGHT 100
#  define LEFT 97
#  define ROT_RIGHT 65363
#  define ROT_LEFT 65361
#  define ESC 65307
#  define RED_BUTTON 79
#  define LIGHTS 48
#  define OPEN_DOOR 57
#  define CLOSERED 33
# endif

typedef struct		s_xy1
{
	int				x;
	int				y;
}					t_xy1;

typedef struct		s_ray
{
	double			x;
	double			y;
}					t_ray;

typedef struct		s_display
{
	double			stepdraw;
	double			texpos;
	int				texxwall;
	int				texywall;
	int				indexdey;
	int				indexdex;
	double			onspritex;
	double			onspritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spritemove;
	int				spriteheight;
	int				spritewidth;
	int				drawstarty;
	unsigned int	colorsprite;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	double			life;
	int				stripe;
	int				texx;
	int				texy;
	int				y;
	int				dsprite;
	int				spritenumber;
	int				cellx;
	int				celly;
	int				txfloor;
	int				tyfloor;
	int				txfloor2;
	int				tyfloor2;
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	float			posz;
	int				pfloor;
	int				maptofree;
	int				keyboard[100000];
	int				index;
	int				bpp;
	int				bpp2[14];
	int				s_line;
	int				s_line2[14];
	int				ed2[14];
	int				ed;
	int				startline;
	int				endline;
	int				side;
	double			*zbuffer;
	int				switchoff;
	char			**map;
	char			*pxl;
	char			*spritenum;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*spritepwd;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				r1;
	int				errorbool;
	int				spritecounted;
	int				r2;
	int				fd;
	double			stepx;
	double			stepy;
	double			camerax;
	double			rotspeed;
	double			dirx;
	double			wallx;
	double			diry;
	double			planex;
	int				sizeminimap;
	int				minimap_x;
	int				minimap_y;
	double			planey;
	int				lineheight;
	double			perwalldist;
	double			pspeed;
	int				mapx;
	int				havekey;
	int				initsuccess;
	int				bmp;
	int				mapy;
	int				*spritex;
	int				*spritey;
	double			*spritedist;
	int				numberofplayer;
	int				widthtext[14];
	int				heighttext[14];
	void			*text_no;
	void			*text_so;
	char			*filename;
	int				mapboleen;
	void			*text_we;
	void			*text_ea;
	void			*text_floor;
	void			*text_ceiling;
	void			*text_life;
	void			*text_gun;
	void			*text_door;
	void			*sprite;
	void			*sprite2;
	void			*sprite3;
	void			*sprite3move;
	void			*sprite4move;
	int				textnum;
	char			*ptr[14];
	clock_t			last_frame;
	clock_t			next_frame;
	unsigned int	color;
	unsigned int	rgbfloor[3];
	unsigned int	rgbceiling[3];
	unsigned int	rgbtemp[3];
	t_ray			player;
	t_ray			d;
	t_ray			deltadist;
	t_ray			sidedist;
	t_xy1			mapi;
}					t_display;

typedef struct		s_bmp_header
{
	int				file_size;
	int				reserved;
	int				offset;
	int				head_size;
	int				width;
	int				height;
	short			planes;
	short			bpp;
	int				compression;
	int				img_size;
	int				x_res;
	int				y_res;
	int				color_palette;
	int				color_prio;
}					t_bmp_h;

typedef struct		s_parse
{
	int				r1;
	int				r2;
	char			**map;
	t_xy1			sizemap;
}					t_parse;

int					parse(int argc, char *str, \
					t_parse *parse, t_display *display);
void				checkbox(t_display *display, char c, int map_x, int map_y);
void				minimap(t_display *display);
int					drawsquare(t_display *display);
int					stocktextures_we(char *line, t_display *display);
int					stocktextures_so(char *line, t_display *display);
int					checkaround(int mapx, int mapy, t_display *display);
int					stocktextures_ea(char *line, t_display *display);
int					stocktextures_no(char *line, t_display *display);
int					stocktextures_s(char *line, t_display *display);
void				printsprite(t_display *display, int index);
int					opendoor(t_display *display);
void				minimap(t_display *display);
void				getxandyofsprite(t_display *display);
int					getverticaldata(t_display *display, int y);
int					gethorizontaldata(t_display *display);
int					checkaround(int mapx, int mapy, t_display *display);
int					switchspriteforsort(t_display *display, int index);
void				rotation(int i, t_display *display);
int					freemap(t_display *display);
void				get_life(t_display *display);
void				loadsprites2(t_display *display);
int					checkifgood2(char c);
void				getinfowalltext(t_display *display, int x);
int					findtexturenum(t_display *display);
void				loadtexturesbonus(t_display *display);
void				getinfosprite(t_display *display, \
					int sprites, int spritenum);
int					key_loop(t_display *display);
void				checkkeybonus(t_display *display);
int					checkcubextension(char *str, t_display *display);
void				countsprite(t_display *display);
void				resizeminimap(t_display *display);
void				loadtextures(t_display *display);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				clear_img_buffer(t_display *display);
int					checkparse(t_display *display, t_parse *parse, int fd);
int					freeandexit(t_display *display);
void				drawgun(t_display *display);
int					gotomap(t_display *display, t_parse *parse, \
					int len, int fd);
int					write_bmp_image(t_display *display, int fd);
void				*draw_image(t_display *display);
void				drawlife(t_display *display);
t_bmp_h				set_bmp_header(t_display *display);
int					put_pxl(t_display *display, int x, int y, unsigned int c);
int					create_bmp(t_display *display);
int					stockresolution(char *line, \
					t_parse *parse, t_display *display);
void				resizelife(t_display *display);
int					stockcolorf(char *line, t_display *display);
int					checkresolution(t_display *display);
int					stockcolorc(char *line, t_display *display);
void				drawloop(t_display *display, int y, int x);
int					replacecharinmap(t_display *display, \
					char *line, int i, int len);
int					draw_line(t_display *display, int x);
void				getxy2(t_parse *parse, int b, char *line, int fd);
int					stockmap(t_parse *parse, t_display *display);
void				getxymap(t_parse *parse, char *filename);
int					strlentoend(char *str);
int					isend(char *line);
int					closebyredbutton(t_display *display);
unsigned int		addsmog(double dist, t_display *display);
int					mallocmap(t_parse *parse, t_display *display);
int					raycasting(t_display *display);
int					ft_keyboard(t_display *display);
int					ft_key_hit(int keycode, t_display *display);
int					sortmap(t_parse *parse, char *line, \
					int len, t_display *display);
int					checkthekey(t_display *display);
int					display(t_parse *parse, t_display *display);
int					sendrayon(t_display *display);
int					showerror(t_display *display, char *str);
int					ft_key_release(int keycode, t_display *display);
int					showraster(t_display *display);
int					searchcomma(char *line);
void				initdisplay(t_display *display, t_parse *parse);
int					moveplayer(int nb, t_display *display);
int					findwall(t_display *display);
int					initparse(t_display *display);
void				sortsprites(t_display *display);
unsigned int		colortoint(unsigned int r, unsigned int g, unsigned int b);
int					moveornot(t_display *display, double tmpx, double tmpy);
char				initposplayer(char pos, int x, int y, t_display *display);
int					newwindow(t_display *display);
int					floodandfill(t_display *display, int mapy, int mapx);
int					drawfloor(t_display *display);
void				putthegun(t_display *display);
unsigned int		addsmog2(double dist, t_display *display);
int					checkthewall(t_display *display);
int					get_next_line(int fd, char **line);
int					ft_atoi(const char *str);
char				*ft_strcpy(char *dest, char *src);
void				showsprite(t_display *display);
int					is_space(char c);
int					ft_strlenght(char *str);
int					numberblank(char *str);
void				loadsprites(t_display *display);
int					parseline(char *line, t_parse *parse, t_display *display);
unsigned int		addsmog3(double dist, \
					t_display *display, unsigned int color);
int					cmp(char *s1, char *s2, size_t n);

#endif
