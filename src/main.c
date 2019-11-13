/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:54:31 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 16:54:14 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **arg)
{
	t_fdf	*fdf;
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf target_file");
		return (0);
	}
	if ((fd = open(arg[1], O_RDONLY)) < 0)
	{
		ft_putendl("error: that file doesn't exist");
		return (0);
	}
	if (!(fdf = new_fdf(fd)))
		return (0);
	(*fdf).ptrs.mlx_ptr = mlx_init();
	(*fdf).ptrs.win_ptr = mlx_new_window((*fdf).ptrs.mlx_ptr, 1920, 1080, "<3");
	mlx_hook(fdf->ptrs.win_ptr, 2, 0, key_press, (void *)fdf);
	mlx_hook(fdf->ptrs.win_ptr, 4, 0, mouse_press, (void *)fdf);
	mlx_hook(fdf->ptrs.win_ptr, 17, 0, close_w, (void *)fdf);
	out_pic(fdf);
	mlx_loop((*fdf).ptrs.mlx_ptr);
	return (0);
}
