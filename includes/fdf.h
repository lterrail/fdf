/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:03:53 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 19:30:55 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define WIDTH 2400
# define HEIGHT 1300
# define PI 3.141

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_E			14

# define KEY_Q			12
# define KEY_W			13

# define KEY_QUIT		53
# define KEY_ZOOM		69
# define KEY_DEZOOM		78

# define KEY_CLEAR		71
# define KEY_COLOR1		83
# define KEY_COLOR2		84
# define KEY_COLOR3		85
# define KEY_COLOR4		86
# define KEY_COLOR5		87
# define KEY_COLOR6		88
# define KEY_COLOR7		89
# define KEY_COLOR8		91
# define KEY_COLOR9		92

# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126

# define ERROR 0
# define SUCCESS 1
# define ERROR_MALLOC -1
# define ERROR_BAD_CHAR -2
# define ERROR_LIMIT_INT -3
# define ERROR_BAD_IDENDATION -4
# define ERROR_NO_FILE -5
# define ERROR_TOO_MANY_FILES -6
# define ERROR_OPEN -7

typedef struct		s_color
{
	int		r;
	int		g;
	int		b;
}					t_color;

typedef struct		s_line
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xincr;
	int		yincr;
	int		cumul;
	int		i;
}					t_line;

typedef struct		s_next
{
	int		xsrc;
	int		ysrc;
	int		xdest;
	int		ydest;
}					t_next;

typedef struct		s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}					t_img;

typedef struct		s_fdf
{
	int				fd;
	t_img			*img;
	t_color			*color;
	void			*mlx;
	void			*win;
	char			*name;
	int				**map;
	int				**coordx;
	int				**coordy;
	int				nb_column;
	int				nb_line;
	float			alti;
	float			rotation;
	float			size;
	int				key;
	int				move_x;
	int				move_y;
	float			incli;
}					t_fdf;

extern int			ft_parse(t_fdf *fdf);
extern int			ft_draw(t_fdf *fdf);
void				ft_debugg(t_fdf *fdf);
void				ft_exit(t_fdf *fdf, int error);
void				init_data(t_fdf *fdf);

int					key_event_press(int keycode, t_fdf *fdf);
int					zoom(int keycode, t_fdf *fdf);
int					alteration(int keycode, t_fdf *fdf);

t_img				*ft_new_image(void *mlx, int width, int height);
int					ft_clear_img(t_img *img);
int					draw_line(t_img *img, t_next *next, t_color *color);

float				coord(t_fdf *fdf, float angle_x, float angle_y, int xory);
float				angle(t_fdf *fdf, float x, float y, int xory);

void				ft_color(t_fdf *fdf, t_color *color, int x, int y);
void				blue1(t_color *color);
void				yellow1(t_color *color);
void				green1(t_color *color);
void				green2(t_color *color);
void				brawn1(t_color *color);
void				brawn2(t_color *color);
void				white(t_color *color);
void				red1(t_color *color);

#endif
