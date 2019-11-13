/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:20:18 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 16:51:07 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_fdf *n_fdf, t_vector3 p_1, int color)
{
	int	r;
	int	g;
	int	b;
	int	i;

	b = color & 0x000000ff;
	g = color & 0x0000ff00;
	r = color & 0x00ff0000;
	i = (p_1.x * n_fdf->bpp / 8 + p_1.y * n_fdf->size_line);
	n_fdf->img_data[i] = b;
	n_fdf->img_data[++i] = g >> 8;
	n_fdf->img_data[++i] = r >> 16;
	n_fdf->img_data[++i] = 0;
}
