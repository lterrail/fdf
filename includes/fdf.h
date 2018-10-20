/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:03:53 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/20 18:48:04 by lterrail         ###   ########.fr       */
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

# define WIDTH 1800
# define HEIGHT 1200
# define EDGE 300
# define LIMIT_Z 200

# define ERROR 0
# define SUCCESS 1
# define ERROR_MALLOC -1
# define ERROR_BAD_CHAR -2
# define ERROR_LIMIT_INT -3
# define ERROR_BAD_IDENDATION -4
# define ERROR_NO_FILE -5
# define ERROR_TOO_MANY_FILES -6

typedef struct		s_fdf
{
	int				fd;
	void			*mlx;
	void			*win;
	char			*name;
	int				**map;
	int				nb_column;
	int				nb_line;
	int				xnext;
	int				ynext;
	int				xlen;
	int				ylen;
	int				x;
	int				y;
}					t_fdf;

extern int			ft_parse(t_fdf *fdf);
extern int			ft_draw(t_fdf *fdf);
void				ft_debugg(t_fdf *fdf);
void				ft_exit(t_fdf *fdf, int error);

#endif
