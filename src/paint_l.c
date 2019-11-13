/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:04:45 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 17:26:07 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap(double *x0, double *x1, double *y0, double *y1)
{
	double swap;

	if (*x0 > *x1)
	{
		swap = *x0;
		*x0 = *x1;
		*x1 = swap;
		swap = *y0;
		*y0 = *y1;
		*y1 = swap;
	}
	if (*x0 == *x1)
		(*x1)++;
}

void		paint_l(t_vector3 p1, t_vector3 p2, t_fdf *n_fdf)
{
	t_vector3	ers;
	int			y_inc;
	t_vector3	p_1;
	t_vector3	p_2;

	p_1 = to_pxl(p1);
	p_2 = to_pxl(p2);
	swap(&(p_1.x), &(p_2.x), &(p_1.y), &(p_2.y));
	ers.x = fabs((p_2.y - p_1.y) / (p_2.x - p_1.x));
	y_inc = (p_1.y > p_2.y) ? -1 : 1;
	ers.y = 0;
	while (p_1.x < p_2.x)
	{
		ers.y += ers.x;
		check_then_paint(n_fdf, p_1);
		while (ers.y > 0.5)
		{
			check_then_paint(n_fdf, p_1);
			p_1.y += y_inc;
			ers.y -= 1;
		}
		p_1.x++;
	}
}
