/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:23:57 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 16:50:18 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3	new_vector3(double x, double y, double z)
{
	t_vector3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
