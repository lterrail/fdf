/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:03:53 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 15:24:05 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_COLOR_H
# define KEY_COLOR_H

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

typedef struct		s_color
{
	int		r;
	int		g;
	int		b;
	int		random_color;
}					t_color;

void				blue1(t_color *color);
void				yellow1(t_color *color);
void				green1(t_color *color);
void				green2(t_color *color);
void				brawn1(t_color *color);
void				brawn2(t_color *color);
void				white(t_color *color);
void				grey1(t_color *color);
void				red1(t_color *color);
void				blue2(t_color *color);

#endif
