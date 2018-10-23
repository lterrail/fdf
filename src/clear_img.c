/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:25:29 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 11:53:30 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_clear_img(t_img *img)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			img->data[(x * (img->bpp / 8)) + (y * img->size_line)] = 0;
			img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 1] = 0;
			img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 2] = 0;
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
