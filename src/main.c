/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:54:41 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/14 14:04:59 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_debugg(t_fdf *fdf)
{
	int		j;
	int		i;

	j = 0;
	ft_printf("name       [%s]\n", fdf->name);
	ft_printf("nb_line    [%d]\n", fdf->nb_line);
	ft_printf("nb_column  [%d]\n", fdf->nb_column);
	ft_printf("{blue}xlen       [%d]{eoc}\n", fdf->xlen);
	ft_printf("{blue}ylen       [%d]{eoc}\n", fdf->ylen);
	while (j < fdf->nb_line)
	{
		i = 0;
		while (i < fdf->nb_column)
		{
			printf("%d ", fdf->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

static t_fdf	*init_fdf(char **av)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->fd = 0;
	// fdf->mlx = mlx_init();
	fdf->win = NULL;
	fdf->nb_column = 0;
	fdf->nb_line = 0;
	fdf->xlen = 0;
	fdf->x = EDGE;
	fdf->y = EDGE;
	fdf->ylen = 0;
	fdf->map = 0;
	fdf->name = av[1];
	return (fdf);
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	int		error;

	error = 0;
	fdf = init_fdf(av);
	if (ac < 2)
		ft_exit(fdf, ERROR_NO_FILE);
	if (ac == 2)
	{
		fdf->fd = open(fdf->name, O_RDONLY);
		if ((error = ft_parse(fdf)) < 0)
			ft_exit(fdf, error);
		if ((error = ft_draw(fdf)) < 0)
			ft_exit(fdf, error);
		ft_debugg(fdf);
		ft_exit(fdf, error);
	}
	else
		ft_exit(fdf, ERROR_TOO_MANY_FILES);
	return (0);
}
