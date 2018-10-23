/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:31:07 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 18:34:42 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	angle(t_fdf *fdf, float x, float y, int xy)
{
	float	pt;
	float	radian;

	radian = fdf->rotation * PI * 180;
	pt = 0;
	if (xy == 1)
		pt = (x - fdf->nb_column / 2) * cos(radian) -
			(y - fdf->nb_line / 2) * sin(radian);
	else if (xy == 0)
		pt = (y - fdf->nb_line / 2) * cos(radian) +
			(x - fdf->nb_column / 2) * sin(radian);
	return (pt);
}

float	coord(t_fdf *fdf, float angle_x, float angle_y, int xy)
{
	float pt;

	pt = 0;
	if (xy == 1)
		pt = (angle_x - angle_y) * fdf->size + (WIDTH / 2);
	else if (xy == 0)
		pt = (angle_x + angle_y) * fdf->size / 2 / fdf->incli + (HEIGHT / 2);
	return (pt);
}
