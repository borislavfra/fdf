/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:43:39 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 17:22:35 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_press_1(int keycode, void *param)
{
	if (keycode == 7)
		((t_fdf *)param)->rotation.x += (double)(5 * M_PI / 180);
	if (keycode == 6)
		((t_fdf *)param)->rotation.z += (double)(5 * M_PI / 180);
	if (keycode == 16)
		((t_fdf *)param)->rotation.y += (double)(5 * M_PI / 180);
	if (keycode == 0)
		((t_fdf *)param)->transform.x += 0.1;
	if (keycode == 2)
		((t_fdf *)param)->transform.x += -0.1;
	if (keycode == 1)
		((t_fdf *)param)->transform.y += -0.1;
	if (keycode == 13)
		((t_fdf *)param)->transform.y += 0.1;
	if (keycode == 34)
		apply_iso(param);
}

static void	key_press_2(int keycode, void *param)
{
	if (keycode == 24)
	{
		((t_fdf *)param)->scale.x *= 1.1;
		((t_fdf *)param)->scale.y *= 1.1;
		((t_fdf *)param)->scale.z *= 1.1;
	}
	if (keycode == 27)
	{
		((t_fdf *)param)->scale.x *= 0.9;
		((t_fdf *)param)->scale.y *= 0.9;
		((t_fdf *)param)->scale.z *= 0.9;
	}
	if (keycode == 35)
	{
		copy_points(((t_fdf *)param)->tmp_points, ((t_fdf *)param)->points,
		((t_fdf *)param)->sizes);
	}
	if (keycode == 8)
	{
		((t_fdf *)param)->scale = new_vector3(1, 1, 1);
		((t_fdf *)param)->transform = new_vector3(0, 0, 0);
		((t_fdf *)param)->rotation = new_vector3(0, 0, 0);
	}
}

int			key_press(int keycode, void *param)
{
	key_press_1(keycode, param);
	key_press_2(keycode, param);
	if (keycode == 53)
		exit(0);
	if ((t_fdf *)param)
		mlx_clear_window(((t_fdf *)param)->ptrs.mlx_ptr,
		((t_fdf *)param)->ptrs.win_ptr);
	out_pic(param);
	return (0);
}

int			mouse_press(int button, int x, int y, void *param)
{
	int	i;
	int	r;
	int	g;
	int b;

	if (button == 1 && (x >= 1870 && x < 1910) && (y >= 20 && y < 60))
	{
		i = (x * ((t_fdf *)param)->bpp / 8 + y * ((t_fdf *)param)->size_line);
		b = (((t_fdf *)param)->img_data[i]) & 0xff;
		g = (((t_fdf *)param)->img_data[++i]) & 0xff;
		r = (((t_fdf *)param)->img_data[++i]) & 0xff;
		((t_fdf *)param)->color = ((r << 16) | (g << 8) | b);
		mlx_clear_window(((t_fdf *)param)->ptrs.mlx_ptr,
		((t_fdf *)param)->ptrs.win_ptr);
		out_pic(param);
	}
	return (0);
}

int			close_w(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
