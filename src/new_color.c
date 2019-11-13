/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:43:03 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 17:25:13 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_light(int start, int end, double pr)
{
	return (int)((1 - pr) * start + pr * end);
}

int			new_color(int start, int end, double pr)
{
	int	r;
	int	g;
	int b;

	b = get_light(start & 0xff, end & 0xff, pr);
	g = get_light(start >> 8 & 0xff, end >> 8 & 0xff, pr);
	r = get_light(start >> 16 & 0xff, end >> 16 & 0xff, pr);
	return ((r << 16) | (g << 8) | b);
}
