/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeltek <ibeltek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:04:00 by ibeltek           #+#    #+#             */
/*   Updated: 2017/02/10 17:15:43 by ibeltek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			**data;
	char			*color;
	int				*x;
	int				*y;
	int				paint;
	int				list_size;
	char			c;
}					t_list;

void				error();
void				read_file(char *av, int flag, char *color);
void				check_file(char *str, int flag, char *color);
void				write_in_lst(char *str, int flag, char *color);
int					list_len(t_list *first, int flag, char *color);
void				create_map(t_list *first, int len);
void				write_in_2arr(char *str, int c, t_list *elem);
char				**put_figure(char **min_map, int y, int x, t_list *first);

#endif
