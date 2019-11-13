/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:13:32 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/08 10:54:24 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector3	**alloc_pp(int y, int x, int flag)
{
	int			i;
	t_vector3	**p;

	i = -1;
	if (!flag)
	{
		p = (t_vector3 **)malloc(sizeof(t_vector3 *) * (y + 1));
		p[y] = NULL;
		while (++i < y)
		{
			p[i] = (t_vector3 *)malloc(sizeof(t_vector3) * (x + 1));
		}
	}
	else
	{
		p = NULL;
	}
	return (p);
}

static t_vector3	**mem_pp(char **tmp, t_vector3 **p)
{
	int		i;
	int		j;
	int		k;
	int		flag;

	i = -1;
	k = -1;
	flag = 0;
	while (tmp[++i] != NULL)
	{
		j = word_count(tmp[i], ' ');
		if (k != j && k != -1 && !flag)
		{
			ft_putendl("error: fdf map contains mistakes");
			flag = 1;
		}
		k = j;
	}
	p = alloc_pp(i, j, flag);
	return (p);
}

static int			check_string(char *c)
{
	int	k;

	k = 0;
	while (c[k] == 32 || (c[k] >= 9 && c[k] <= 13))
		k++;
	if (c[k] == '-' || c[k] == '+')
		k++;
	if (c[k] == '\0')
		return (0);
	while (c[k++] != '\0')
		if (c[k - 1] < 48 || c[k - 1] > 57)
			return (0);
	return (1);
}

static int			check_chars(char **tmp)
{
	int		i;
	int		j;
	char	**a;

	i = -1;
	while (tmp[++i] != NULL)
	{
		j = -1;
		a = ft_strsplit(tmp[i], ' ');
		while (a[++j] != NULL)
		{
			if (!check_string(a[j]))
			{
				ft_dell(&a);
				ft_putendl("warning: fdf map contains wrong symbols");
				return (0);
			}
		}
		ft_dell(&a);
	}
	return (1);
}

t_vector3			**lines_points(char **tmp, t_vector3 *sizes)
{
	t_vector3	**p;
	int			i;
	int			j;
	char		**a;

	p = NULL;
	i = -1;
	check_chars(tmp);
	if ((p = mem_pp(tmp, p)) == NULL)
		return (NULL);
	while (tmp[++i] != NULL)
	{
		j = -1;
		a = ft_strsplit(tmp[i], ' ');
		while (a[++j] != NULL)
			p[i][j] = new_vector3(j, ft_atoi(a[j]) * 0.5, i);
		ft_dell(&a);
	}
	*sizes = new_vector3(j, i, 0);
	return (p);
}
