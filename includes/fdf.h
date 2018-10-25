/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:03:53 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 21:08:22 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "key_color.h"

# define WIDTH 2400
# define HEIGHT 1300
# define LIMIT_ZOOM -20000
# define PI 3.141

# define ERROR 0
# define SUCCESS 1
# define ERROR_MALLOC -1
# define ERROR_BAD_CHAR -2
# define ERROR_LIMIT_INT -3
# define ERROR_BAD_IDENDATION -4
# define ERROR_NO_FILE -5
# define ERROR_TOO_MANY_FILES -6
# define ERROR_OPEN -7
# define ERROR_NO_DATA -8

typedef struct		s_pt
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xincr;
	int		yincr;
	int		cumul;
	int		i;
}					t_pt;

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

int					ft_parse(t_fdf *fdf, int fd);
int					ft_draw(t_fdf *fdf);
void				ft_debugg(t_fdf *fdf);
void				ft_exit(t_fdf *fdf, int error);
void				ft_error(int error);
void				init_data(t_fdf *fdf);
void				ft_display_usage(t_fdf *fdf);

int					key_event_press(int keycode, t_fdf *fdf);
int					zoom(int keycode, t_fdf *fdf);
int					alteration(int keycode, t_fdf *fdf);

t_img				*ft_new_image(void *mlx, int width, int height);
int					ft_clear_img(t_img *img);
int					draw_line(t_img *img, t_next *next, t_color *color);

float				coord(t_fdf *fdf, float angle_x, float angle_y, int xory);
float				angle(t_fdf *fdf, float x, float y, int xory);
void				ft_color(t_fdf *fdf, t_color *color, int x, int y);

#endif
