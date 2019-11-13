/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:30:08 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 16:51:15 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_rotation(t_vector3 *p1, t_vector3 rot_mat)
{
	double		x;
	double		y;
	double		z;

	if (rot_mat.x != 0)
	{
		y = cos(rot_mat.x) * p1->y + sin(rot_mat.x) * p1->z;
		z = -sin(rot_mat.x) * p1->y + cos(rot_mat.x) * p1->z;
		p1->y = y;
		p1->z = z;
	}
	if (rot_mat.y != 0)
	{
		x = cos(rot_mat.y) * p1->x + sin(rot_mat.y) * p1->z;
		z = -sin(rot_mat.y) * p1->x + cos(rot_mat.y) * p1->z;
		p1->x = x;
		p1->z = z;
	}
	if (rot_mat.z != 0)
	{
		x = cos(rot_mat.z) * p1->x - sin(rot_mat.z) * p1->y;
		y = sin(rot_mat.z) * p1->x + cos(rot_mat.z) * p1->y;
		p1->x = x;
		p1->y = y;
	}
}

void	apply_scale(t_vector3 *p1, t_vector3 *p2, t_vector3 scale)
{
	if (p1 != NULL)
		*p1 = v3_multiply(*p1, scale);
	if (p2 != NULL)
		*p2 = v3_multiply(*p2, scale);
}

void	apply_transform(t_vector3 *p1, t_vector3 *p2, t_vector3 tran_mat)
{
	if (p1 != NULL)
		*p1 = v3_add(*p1, tran_mat);
	if (p2 != NULL)
		*p2 = v3_add(*p2, tran_mat);
}

void	apply_iso(t_fdf *n_fdf)
{
	t_vector3	*p;
	t_vector3	np;
	int			i;
	int			j;

	j = 0;
	while (j < n_fdf->sizes.y)
	{
		i = 0;
		while (i < n_fdf->sizes.x)
		{
			p = &(n_fdf->points[j][i]);
			np = *p;
			np.x = 1 / sqrt(6) * (sqrt(3) * p->x + p->z * -sqrt(3));
			np.y = 1 / sqrt(6) * (p->x + 2 * p->y + p->z);
			np.z = 1 / sqrt(6) * (sqrt(2) * p->x + p->y * -sqrt(2) +
			p->z * sqrt(2));
			p->x = np.x;
			p->y = np.y;
			p->z = np.z;
			i++;
		}
		j++;
	}
}
