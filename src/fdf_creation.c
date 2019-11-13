/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:34:28 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 17:24:29 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector3	**create_points(t_vector3 **points, t_vector3 sizes)
{
	t_vector3	**n_points;
	int			i;
	int			j;

	i = 0;
	n_points = (t_vector3 **)malloc(sizeof(t_vector3 *) * sizes.y);
	while (i < sizes.y)
		n_points[i++] = (t_vector3 *)malloc(sizeof(t_vector3) * sizes.x);
	j = 0;
	while (j < sizes.y)
	{
		i = 0;
		while (i < sizes.x)
		{
			n_points[j][i] = points[j][i];
			i++;
		}
		j++;
	}
	return (n_points);
}

static void			all_y_plus(t_fdf *n_fdf, int val)
{
	int		i;
	int		j;

	i = 0;
	while (i < n_fdf->sizes.y)
	{
		j = 0;
		while (j < n_fdf->sizes.x)
		{
			n_fdf->points[i][j].x += val;
			n_fdf->points[i][j].z += val;
			n_fdf->points[i][j].y += val;
			j++;
		}
		i++;
	}
}

static t_vector3	find_mxs(t_fdf *n_fdf)
{
	int			i;
	int			j;
	t_vector3	maxs;

	i = -1;
	maxs = (*n_fdf).points[0][0];
	while (++i < (*n_fdf).sizes.y)
	{
		j = -1;
		while (++j < (*n_fdf).sizes.x)
		{
			if ((*n_fdf).points[i][j].x > maxs.x)
				maxs.x = (*n_fdf).points[i][j].x;
			if ((*n_fdf).points[i][j].y > maxs.y)
				maxs.y = (*n_fdf).points[i][j].y;
			if ((*n_fdf).points[i][j].z > maxs.z)
				maxs.z = (*n_fdf).points[i][j].z;
		}
	}
	all_y_plus(n_fdf, 1);
	maxs = v3_add(new_vector3(1, 1, 1), maxs);
	return (maxs);
}

static void			to_world(t_fdf *n_fdf)
{
	t_vector3	mxs;
	int			i;
	int			j;
	t_vector3	*sw;

	i = 0;
	mxs = find_mxs(n_fdf);
	while (i < (*n_fdf).sizes.y)
	{
		j = 0;
		while (j < (*n_fdf).sizes.x)
		{
			sw = &(*n_fdf).points[i][j];
			sw->x = (sw->x * 2 / mxs.x - 1) * 0.5;
			sw->z = (sw->z * 2 / mxs.z - 1) * 0.5;
			sw->y = (sw->y * 2 / mxs.y - 1) * -0.2;
			n_fdf->tmp_points[i][j] = new_vector3(sw->x, sw->y, sw->z);
			j++;
		}
		i++;
	}
}

t_fdf				*new_fdf(int fd)
{
	t_fdf	*n_fdf;
	char	**str;

	n_fdf = (t_fdf *)malloc(sizeof(t_fdf));
	(*n_fdf).rotation = new_vector3(0, 0, 0);
	(*n_fdf).scale = new_vector3(1, 1, 1);
	(*n_fdf).transform = new_vector3(0, 0, 0);
	(*n_fdf).sizes = new_vector3(0, 0, 0);
	str = r_lines(fd);
	(*n_fdf).points = lines_points(str, &(n_fdf->sizes));
	ft_dell(&str);
	if ((*n_fdf).points == NULL)
		return (NULL);
	(*n_fdf).tmp_points = create_points(n_fdf->points, n_fdf->sizes);
	(*n_fdf).prj = 0;
	(*n_fdf).img_ptr = NULL;
	(*n_fdf).color = 0x0000b4eb;
	to_world(n_fdf);
	return (n_fdf);
}
