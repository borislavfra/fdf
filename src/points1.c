/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:35:07 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 16:50:31 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		copy_points(t_vector3 **source, t_vector3 **def, t_vector3 sizes)
{
	int			i;
	int			j;

	i = -1;
	while (++i < sizes.y)
	{
		j = -1;
		while (++j < sizes.x)
			def[i][j] = source[i][j];
	}
}
