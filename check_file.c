/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeltek <ibeltek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:37:57 by ibeltek           #+#    #+#             */
/*   Updated: 2017/02/10 17:04:54 by ibeltek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	check_connection(char **str)
{
	int		i;
	int		j;
	int		joint;

	j = 0;
	joint = 0;
	while (str[j] != NULL)
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j + 1] != NULL && str[j][i] == '#' && str[j + 1][i] == '#')
				joint++;
			if (str[j][i] == '#' && str[j][i + 1] == '#')
				joint++;
			if (str[j][i] == '#' && str[j][i - 1] == '#')
				joint++;
			if (j > 0 && str[j][i] == '#' && str[j - 1][i] == '#')
				joint++;
			i++;
		}
		j++;
	}
	if (joint < 5)
		error();
}

static void	check_figure(char **str)
{
	int		i;
	int		j;
	int		point;
	int		hash;

	j = -1;
	point = 0;
	hash = 0;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (str[0][0] != '#' && str[0][0] != '.')
				error();
			if (str[j][i] == '.')
				point++;
			if (str[j][i] == '#')
				hash++;
		}
	}
	(point == 12 && hash == 4) ? check_connection(str) : error();
}

static void	find_xy(char **str, t_list *elem)
{
	int		i;
	int		j;
	int		a;
	int		b;

	j = -1;
	a = -1;
	b = -1;
	while (str[++j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '#')
			{
				elem->x[++a] = i;
				elem->y[++b] = j;
			}
			i++;
		}
	}
}

void		write_in_2arr(char *str, int c, t_list *elem)
{
	int		j;
	int		k;
	int		i;

	i = c;
	j = -1;
	while (++j < 4)
	{
		k = 0;
		elem->data[j] = (char *)malloc(sizeof(char) * 5);
		while (k < 4)
			elem->data[j][k++] = str[i++];
		if (str[i] != '\n')
			error();
		elem->data[j][k] = '\0';
		i++;
	}
	elem->data[j] = NULL;
	check_figure(elem->data);
	find_xy(elem->data, elem);
}

void		check_file(char *str, int flag, char *color)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '.' && str[i] != '#' && str[i] != '\n') ||
			(str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\n') ||
			(str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0') ||
			(str[i] != '\n' && str[i + 1] == '\0'))
			error();
		i++;
	}
	write_in_lst(str, flag, color);
}
