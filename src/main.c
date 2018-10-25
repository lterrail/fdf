/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:54:41 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 21:24:23 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			init_data(t_fdf *fdf)
{
	fdf->rotation = 0;
	fdf->key = 0;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->incli = 2;
	fdf->alti = 0.1;
	fdf->color->r = 255;
	fdf->color->g = 255;
	fdf->color->b = 255;
	fdf->color->random_color = 255;
}

static t_fdf	*init_fdf(char **av, t_color *color)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	fdf->color = color;
	fdf->mlx = mlx_init();
	fdf->name = av[1];
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, fdf->name);
	fdf->nb_column = 0;
	fdf->nb_line = 0;
	fdf->map = 0;
	fdf->coordx = 0;
	fdf->coordy = 0;
	init_data(fdf);
	return (fdf);
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	t_color	*color;
	int		error;
	int		fd;

	error = 0;
	color = NULL;
	if (ac != 2)
		ft_error(ERROR_NO_FILE);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error(ERROR_OPEN);
	if (!(fdf = init_fdf(av, color)))
		ft_exit(fdf, ERROR_MALLOC);
	if (!(fdf->img = ft_new_image(fdf->mlx, WIDTH, HEIGHT)))
		ft_exit(fdf, ERROR_MALLOC);
	if ((error = ft_parse(fdf, fd)) < 0)
		ft_exit(fdf, error);
	fdf->size = WIDTH / fdf->nb_column / 3;
	ft_draw(fdf);
	mlx_hook(fdf->win, 2, 0, &key_event_press, fdf);
	mlx_loop(fdf->mlx);
	ft_exit(fdf, error);
	return (0);
}
