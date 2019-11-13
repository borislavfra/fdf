/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_alter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 09:30:48 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 17:27:43 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	amtp(t_vector3 p1, t_vector3 p2,
		t_fdf *n_fdf)
{
	apply_scale(&p1, &p2, (*n_fdf).scale);
	apply_transform(&p1, &p2, (*n_fdf).transform);
	apply_rotation(&p1, (*n_fdf).rotation);
	apply_rotation(&p2, (*n_fdf).rotation);
	paint_l(p1, p2, n_fdf);
}

static void	amtpd(t_vector3 p1, t_fdf *n_fdf)
{
	t_vector3 p_1;

	apply_scale(&p1, NULL, n_fdf->scale);
	apply_transform(&p1, NULL, n_fdf->transform);
	apply_rotation(&p1, n_fdf->rotation);
	p_1 = to_pxl(p1);
	check_then_paint(n_fdf, p_1);
}

void		add_lines(t_fdf *n_fdf)
{
	int			i;
	int			j;

	i = 0;
	while (i < (*n_fdf).sizes.y)
	{
		j = 0;
		while (j < (*n_fdf).sizes.x)
		{
			if (i + 1 < (*n_fdf).sizes.y)
				amtp((*n_fdf).points[i][j],
				(*n_fdf).points[i + 1][j], n_fdf);
			if (j + 1 < (*n_fdf).sizes.x)
				amtp((*n_fdf).points[i][j],
				(*n_fdf).points[i][j + 1], n_fdf);
			if (!(i + 1 < n_fdf->sizes.x) && !(j + 1 < n_fdf->sizes.y))
				amtpd(n_fdf->points[i][j], n_fdf);
			j++;
		}
		i++;
	}
}
