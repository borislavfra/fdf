/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:40:10 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 17:26:00 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	out_pallet(t_fdf *n_fdf)
{
	int		s_x;
	int		s_y;
	double	pr;
	int		cc;

	s_y = 20;
	pr = 1;
	while (s_y < 60)
	{
		s_x = 1870;
		while (s_x < 1910)
		{
			cc = new_color(0xffd20f, 0x552cff, pr);
			set_color(n_fdf, new_vector3(s_x, s_y, 0), cc);
			s_x++;
			if (s_x % 10 == 0)
				pr -= 0.0625;
		}
		s_y++;
		if (s_y % 10 != 0)
			pr += 0.25;
	}
}

void		out_pic(t_fdf *n_fdf)
{
	int endian;

	if ((n_fdf->img_ptr))
		mlx_destroy_image(n_fdf->ptrs.mlx_ptr, n_fdf->img_ptr);
	n_fdf->img_ptr = mlx_new_image(n_fdf->ptrs.mlx_ptr, WIDTH, HEIGHT);
	n_fdf->img_data = mlx_get_data_addr(n_fdf->img_ptr, &(n_fdf->bpp),
	&(n_fdf->size_line), &endian);
	add_lines(n_fdf);
	out_pallet(n_fdf);
	mlx_put_image_to_window(n_fdf->ptrs.mlx_ptr,
	n_fdf->ptrs.win_ptr, n_fdf->img_ptr, 0, 0);
}
