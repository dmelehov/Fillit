/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeltek <ibeltek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:57:31 by ibeltek           #+#    #+#             */
/*   Updated: 2017/02/09 22:44:18 by ibeltek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_empty_place(char **min_map, int y, int x, t_list *first)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	i = 0;
	flag = 0;
	while (j < 4 && i < 4 && min_map[y + first->y[j]] != NULL &&
		min_map[y + first->y[j]][x + first->x[i]] != '\0')
	{
		if (min_map[y + first->y[j]][x + first->x[i]] == '.')
			flag++;
		j++;
		i++;
	}
	if (flag == 4)
		return (4);
	return (0);
}

void	delete_last_figure(char **min_map, int y, int x, t_list *first)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < 4 && ++i < 4)
		min_map[y + first->y[j]][x + first->x[i]] = '.';
}

void	paste_figure(char **min_map, int y, int x, t_list *first)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < 4 && ++i < 4)
		min_map[y + first->y[j]][x + first->x[i]] = first->c;
}

char	**put_figure(char **min_map, int y, int x, t_list *first)
{
	y = -1;
	if (first == NULL)
		return (min_map);
	while (min_map[++y])
	{
		x = -1;
		while (min_map[y][++x])
		{
			if (check_empty_place(min_map, y, x, first) == 4)
			{
				paste_figure(min_map, y, x, first);
				if (put_figure(min_map, y, x, first->next) == NULL)
					delete_last_figure(min_map, y, x, first);
				else
					return (min_map);
			}
		}
	}
	if (min_map[y] == NULL && first != NULL)
		create_map(first, first->list_size++);
	return (NULL);
}
