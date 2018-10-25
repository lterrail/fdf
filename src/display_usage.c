/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:50:26 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 20:45:03 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_display_usage(t_fdf *fdf)
{
	char	*x;
	char	*y;

	x = ft_itoa(fdf->coordx[0][0]);
	y = ft_itoa(fdf->coordy[0][0]);
	mlx_string_put(fdf->mlx, fdf->win, 50, 170, 0xFFFFFF, "coord_x  :");
	mlx_string_put(fdf->mlx, fdf->win, 50, 190, 0xFFFFFF, "coord_y  :");
	mlx_string_put(fdf->mlx, fdf->win, 160, 170, 0xFFFFFF, x);
	mlx_string_put(fdf->mlx, fdf->win, 160, 190, 0xFFFFFF, y);
	mlx_string_put(fdf->mlx, fdf->win, 50, 70, 0xFFFFFF, "Rotation : AWSD");
	mlx_string_put(fdf->mlx, fdf->win, 50, 110, 0xFFFFFF, "Move     : Arrow");
	mlx_string_put(fdf->mlx, fdf->win, 50, 50, 0xFFFFFF, "Altitude : QE");
	mlx_string_put(fdf->mlx, fdf->win, 50, 90, 0xFFFFFF, "Color    : 1-9");
	mlx_string_put(fdf->mlx, fdf->win, 50, 130, 0xFFFFFF, "Reset    : Clear\n");
	free(x);
	free(y);
}
