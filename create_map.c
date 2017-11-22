/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeltek <ibeltek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:13:10 by ibeltek           #+#    #+#             */
/*   Updated: 2017/02/10 17:19:15 by ibeltek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_map(char **min_map, int flag, char *color)
{
	int		y;
	int		x;
	int		i;
	char	color_iter[5];

	y = -1;
	while (min_map[++y])
	{
		x = -1;
		while (min_map[y][++x])
		{
			if (flag == 1)
			{
				i = -1;
				while (color[++i])
					color_iter[i] = color[i];
				write(1, "\x1b[0m", 4);
				color_iter[3] = ((min_map[y][x] - 64) % 10) + 48;
				write(1, &color_iter, 5);
			}
			write(1, &min_map[y][x], 1);
		}
		write(1, &"\n", 1);
	}
}

static void	move_to_zero(t_list *first)
{
	int		i;
	int		j;
	int		c;
	int		k;

	while (first)
	{
		j = -1;
		c = 3;
		while (++j < 4)
			if (first->x[j] < c)
				c = first->x[j];
		j = -1;
		while (++j < 4)
			first->x[j] = first->x[j] - c;
		i = -1;
		k = 3;
		while (++i < 4)
			if (first->y[i] < k)
				k = first->y[i];
		i = -1;
		while (++i < 4)
			first->y[i] = first->y[i] - k;
		first = first->next;
	}
}

void		create_map(t_list *first, int len)
{
	int		size;
	char	**min_map;
	int		x;
	int		y;

	size = 2;
	x = 0;
	while ((size * size) < (len * 4))
		size++;
	min_map = (char **)malloc(sizeof(char *) * ((size * size) + 1));
	while (x < size)
	{
		y = -1;
		min_map[x] = (char *)malloc(sizeof(char) * (size + 1));
		while (++y < size)
			min_map[x][y] = '.';
		min_map[x][y] = '\0';
		x++;
	}
	min_map[x] = NULL;
	x = 0;
	y = 0;
	move_to_zero(first);
	if (put_figure(min_map, y, x, first) != NULL && first->c == 'A')
		print_map(min_map, first->paint, first->color);
}
