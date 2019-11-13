/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:07:48 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/08 10:30:30 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef struct	s_ptrs
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_ptrs;

typedef struct	s_vector3
{
	double		x;
	double		y;
	double		z;
}				t_vector3;

typedef struct	s_fdf
{
	t_vector3	transform;
	t_vector3	rotation;
	t_vector3	scale;
	t_vector3	**points;
	t_vector3	**tmp_points;
	t_vector3	sizes;
	t_ptrs		ptrs;
	int			color;
	int			prj;
	int			bpp;
	int			size_line;
	void		*img_ptr;
	char		*img_data;
}				t_fdf;

void			paint_l(t_vector3 p1, t_vector3 p2, t_fdf *n_fdf);
t_vector3		new_vector3(double x, double y, double z);
char			**r_lines(int fd);
t_vector3		**lines_points(char **tmp, t_vector3 *sizes);
void			ft_dell(char ***s);
t_vector3		to_pxl(t_vector3 p);
void			set_color(t_fdf *n_fdf, t_vector3 p_1, int color);
void			check_then_paint(t_fdf *n_fdf, t_vector3 p_1);
t_fdf			*new_fdf(int fd);
t_vector3		v3_multiply(t_vector3 v1, t_vector3 v2);
t_vector3		v3_add(t_vector3 v1, t_vector3 v2);
void			apply_iso(t_fdf *n_fdf);
void			apply_transform(t_vector3 *p1, t_vector3 *p2,
				t_vector3 tran_mat);
void			apply_scale(t_vector3 *p1, t_vector3 *p2, t_vector3 scale);
void			apply_rotation(t_vector3 *p1, t_vector3 rot_mat);
int				mouse_press(int button, int x, int y, void *param);
int				close_w(void *param);
void			copy_points(t_vector3 **source, t_vector3 **def,
				t_vector3 sizes);
void			out_pic(t_fdf *n_fdf);
int				new_color(int start, int end, double pr);
void			add_lines(t_fdf *n_fdf);
int				key_press(int keycode, void *param);
int				word_count(char const *s, char c);

#endif
