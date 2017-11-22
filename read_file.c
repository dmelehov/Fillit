/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeltek <ibeltek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:12:44 by ibeltek           #+#    #+#             */
/*   Updated: 2017/02/10 17:17:30 by ibeltek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define BUF_SIZE 550

void		error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void		read_file(char *av, int flag, char *color)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error();
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (ret > 546)
		error();
	if (ret == 0)
		error();
	close(fd);
	check_file(buf, flag, color);
}

int			main(int ac, char **av)
{
	int		flag;

	if (ac == 2 || ac == 3)
	{
		if (ac == 2)
			flag = 0;
		if (ac == 3 && (ft_strcmp(av[2], "color_output") == 0))
			flag = 1;
		read_file(av[1], flag, "\x1b[31m");
	}
	else
		error();
	return (0);
}
