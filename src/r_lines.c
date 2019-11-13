/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_lines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:12:31 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/07 18:27:17 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**create_pp(int j, char **str)
{
	char	**astr;

	astr = (char **)malloc(sizeof(char *) * (j + 1));
	astr[j - 1] = ft_strdup(*str);
	astr[j] = NULL;
	ft_strdel(str);
	return (astr);
}

static char	**copy_pp(char **str, int size)
{
	int		i;
	char	**astr;

	astr = (char **)malloc(sizeof(char *) * (size + 1));
	astr[size] = NULL;
	i = -1;
	while (str[++i] != NULL)
		astr[i] = ft_strdup(str[i]);
	return (astr);
}

char		**r_lines(int fd)
{
	int		j;
	char	**astr;
	char	**tmp;
	char	*str;
	int		i;

	j = 1;
	while (get_next_line(fd, &str))
	{
		i = -1;
		astr = create_pp(j, &str);
		if (j != 1)
		{
			while (++i < j - 1)
				astr[i] = ft_strdup(tmp[i]);
			ft_dell(&tmp);
		}
		tmp = copy_pp(astr, j++);
		ft_dell(&astr);
	}
	return (tmp);
}
