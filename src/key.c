/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 10:45:33 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 19:30:11 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_zoom(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_ZOOM)
		fdf->size = fdf->size * 1.5;
	else if (keycode == KEY_DEZOOM)
	{
		if (fdf->size > 1)
			fdf->size = fdf->size * 0.5;
	}
}

static void	ft_parse_color(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_COLOR1)
		fdf->key = 1;
	else if (keycode == KEY_COLOR2)
		fdf->key = 2;
	else if (keycode == KEY_COLOR3)
		fdf->key = 3;
	else if (keycode == KEY_COLOR4)
		fdf->key = 4;
	else if (keycode == KEY_COLOR5)
		fdf->key = 5;
	else if (keycode == KEY_COLOR6)
		fdf->key = 6;
	else if (keycode == KEY_COLOR7)
		fdf->key = 7;
	else if (keycode == KEY_COLOR8)
		fdf->key = 8;
}

static void	ft_move(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_LEFT)
		fdf->move_x -= 5;
	else if (keycode == KEY_RIGHT)
		fdf->move_x += 5;
	else if (keycode == KEY_UP)
		fdf->move_y -= 5;
	else if (keycode == KEY_DOWN)
		fdf->move_y += 5;
}

static void	ft_rotation(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_A)
		fdf->rotation += 0.0001;
	else if (keycode == KEY_D)
		fdf->rotation -= 0.0001;
	else if (keycode == KEY_W)
	{
		if (fdf->incli < 8)
			fdf->incli += 0.2;
	}
	else if (keycode == KEY_S)
	{
		if (fdf->incli > 1)
			fdf->incli -= 0.2;
	}
}

static void	ft_altitude(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_Q)
		fdf->alti += 0.15;
	else if (keycode == KEY_E)
		fdf->alti -= 0.15;
}

int			key_event_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_QUIT)
		ft_exit(fdf, 0);
	ft_clear_img(fdf->img);
	if (keycode == KEY_ZOOM || keycode == KEY_DEZOOM)
		ft_zoom(fdf, keycode);
	else if (keycode >= 83 && keycode <= 91)
		ft_parse_color(fdf, keycode);
	else if (keycode >= 123 && keycode <= 126)
		ft_move(fdf, keycode);
	else if ((keycode >= 0 && keycode <= 3) || keycode == KEY_W)
		ft_rotation(fdf, keycode);
	else if (keycode == KEY_Q || keycode == KEY_E)
		ft_altitude(fdf, keycode);
	else if (keycode == KEY_CLEAR)
		init_data(fdf);
	ft_draw(fdf);
	return (SUCCESS);
}
