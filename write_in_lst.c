/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeltek <ibeltek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:34:01 by ibeltek           #+#    #+#             */
/*   Updated: 2017/02/10 17:12:23 by ibeltek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list		*new_elem(char *str, int i)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	elem->data = (char **)malloc(sizeof(char *) * 21);
	elem->x = (int *)malloc(sizeof(char *) * 5);
	elem->y = (int *)malloc(sizeof(char *) * 5);
	write_in_2arr(str, i, elem);
	elem->next = NULL;
	return (elem);
}

int			list_len(t_list *first, int flag, char *color)
{
	int		i;
	t_list	*begin;
	char	k;

	i = 0;
	k = 65;
	begin = first;
	while (first)
	{
		first->c = k;
		first->paint = flag;
		first->color = color;
		first = first->next;
		k++;
		i++;
	}
	first = begin;
	while (first)
	{
		first->list_size = i;
		first = first->next;
	}
	return (begin->list_size);
}

void		write_in_lst(char *str, int flag, char *color)
{
	t_list	*first;
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i])
		first = new_elem(str, i);
	if (str[i + 20] != '\0')
	{
		i = i + 21;
		temp = new_elem(str, i);
		first->next = temp;
	}
	if (str[i + 20] != '\0')
	{
		while (str[i + 20])
		{
			i = i + 21;
			temp->next = new_elem(str, i);
			temp = temp->next;
		}
	}
	create_map(first, list_len(first, flag, color));
}
