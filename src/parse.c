/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:10:23 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 21:29:59 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_count_int(t_fdf *fdf, char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str || str[i + 1] == '\0' || str[i] == ' ')
		return (ERROR_NO_DATA);
	while (str[i])
	{
		while ((str[i] == '-' && str[i + 1] != '-' && str[i + 1] != ' ')
			|| (str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i] == '\0')
			count++;
		else if (str[i] == ' ' && str[i + 1] != ' ')
		{
			i++;
			count++;
		}
		else
			return (ERROR_BAD_CHAR);
	}
	if (fdf->nb_column != 0 && fdf->nb_column != count)
		return (ERROR_BAD_IDENDATION);
	return (count);
}

static int		ft_create_map(t_fdf *fdf)
{
	int		i;
	int		**tmp_map;

	i = 0;
	if (!(tmp_map = (int **)malloc(sizeof(int *) * (fdf->nb_line + 2))))
		return (ERROR_MALLOC);
	while (i < fdf->nb_line)
	{
		tmp_map[i] = fdf->map[i];
		i++;
	}
	if (fdf->map)
		free(fdf->map);
	fdf->map = tmp_map;
	fdf->map[fdf->nb_line + 1] = 0;
	return (SUCCESS);
}

static int		ft_create_tabyx(t_fdf *fdf)
{
	int		i;

	if (!(fdf->coordx = (int **)malloc(sizeof(int *) * (fdf->nb_line + 1))))
		return (ERROR_MALLOC);
	if (!(fdf->coordy = (int **)malloc(sizeof(int *) * (fdf->nb_line + 1))))
		return (ERROR_MALLOC);
	i = -1;
	while (++i < fdf->nb_line)
	{
		if (!(fdf->coordx[i] = (int *)malloc(sizeof(int) * fdf->nb_column)))
			return (ERROR_MALLOC);
		if (!(fdf->coordy[i] = (int *)malloc(sizeof(int) * fdf->nb_column)))
			return (ERROR_MALLOC);
	}
	fdf->coordx[fdf->nb_line] = 0;
	fdf->coordy[fdf->nb_line] = 0;
	return (SUCCESS);
}

static int		ft_load_map(t_fdf *fdf, char *tmp)
{
	int		deci;
	int		ptr;
	int		value;

	deci = 0;
	ptr = 0;
	if (!(fdf->map[fdf->nb_line] = (int *)malloc(sizeof(int) * fdf->nb_column)))
		return (ERROR_MALLOC);
	while (deci < fdf->nb_column)
	{
		value = ft_atoi(&tmp[ptr]);
		if (ft_bigger_than_integer(&tmp[ptr], ft_nbrlen(value)))
		{
			free(fdf->map[fdf->nb_line]);
			return (ERROR_LIMIT_INT);
		}
		fdf->map[fdf->nb_line][deci] = value;
		deci++;
		while (tmp[ptr] && (tmp[ptr] == '-' || (tmp[ptr] >= '0'
			&& tmp[ptr] <= '9')))
			ptr++;
		if (tmp[ptr] == ' ')
			ptr++;
	}
	return (SUCCESS);
}

int				ft_parse(t_fdf *fdf, int fd)
{
	char	*line;
	int		error;

	while (get_next_line(fd, &line) > 0)
	{
		if ((error = ft_count_int(fdf, line)) < 0)
		{
			free(line);
			return (error);
		}
		fdf->nb_column = error;
		if ((error = ft_create_map(fdf)) < 0
			|| (error = ft_load_map(fdf, line)) < 0)
		{
			free(line);
			return (error);
		}
		fdf->nb_line++;
		free(line);
	}
	if (!(ft_create_tabyx(fdf)))
		return (ERROR_MALLOC);
	return (SUCCESS);
}
