/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:10:23 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/14 12:46:12 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_create_map(t_fdf *fdf)
{
	int		i;
	int		**tmp_map;

	i = 0;
	if (!(tmp_map = (int **)malloc(sizeof(int *) * (fdf->nb_line + 1))))
		return (ERROR_MALLOC);
	while (i < fdf->nb_line)
	{
		tmp_map[i] = fdf->map[i];
		i++;
	}
	if (fdf->map)
		free(fdf->map);
	fdf->map = tmp_map;
	return (SUCCESS);
}

static int	ft_count_int(t_fdf *fdf, char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str || str[i] == ' ')
		return (ERROR);
	while (str[i])
	{
		while ((str[i] == '-' && str[i + 1] != '-') || (str[i] >= '0'
			&& str[i] <= '9'))
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
	if (fdf->nb_column && fdf->nb_column != count)
		return (ERROR_BAD_IDENDATION);
	return (count);
}

static int	ft_load_map(t_fdf *fdf, char *tmp)
{
	int		deci;
	int		ptr;
	int		value;

	deci = 0;
	ptr = 0;
	if (!(fdf->map[fdf->nb_line] = malloc(sizeof(int) * fdf->nb_column + 1)))
		return (ERROR_MALLOC);
	while (deci < fdf->nb_column)
	{
		value = ft_atoi(&tmp[ptr]);
		if (value > LIMIT_Z || value < -LIMIT_Z)
			return (ERROR_LIMIT_INT);
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

extern int	ft_parse(t_fdf *fdf)
{
	char	*line;
	int		error;

	while (get_next_line(fdf->fd, &line) > 0)
	{
		if ((error = ft_create_map(fdf)) < 0)
		{
			free(line);
			return (error);
		}
		if ((error = ft_count_int(fdf, line)) < 0)
		{
			free(line);
			return (error);
		}
		fdf->nb_column = error;
		if ((error = ft_load_map(fdf, line)) < 0)
		{
			free(line);
			return (error);
		}
		fdf->nb_line++;
		free(line);
	}
	return (SUCCESS);
}
