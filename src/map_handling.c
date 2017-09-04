/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:41:11 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/01 14:08:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	increment_contains(t_mapcontains *con, char c)
{
	if (c == ' ')
		con->space++;
	else if (c == '1')
		con->wall++;
	else if (c == 'P')
		con->player++;
	else if (c == 'E')
		con->exit++;
	else if (c == '\n')
		con->newline++;
}

static void	set_contains_to_zero(t_mapcontains *c)
{
	c->space = 0;
	c->wall = 0;
	c->player = 0;
	c->exit = 0;
	c->newline = 0;
}

int			preliminary_char_check(char *map_name)
{
	int				fd;
	int				num;
	int				buf_len;
	char			buf[51];
	t_mapcontains	c;

	if ((fd = open(map_name, O_RDONLY)) == -1)
		return (ft_puterror("Map open error... ", 0));
	set_contains_to_zero(&c);
	while (read(fd, buf, 50))
	{
		num = -1;
		buf_len = (int)ft_strlen(buf);
		while (++num < buf_len)
		{
			if (buf[num] != ' ' && buf[num] != '1' && buf[num] != 'P'
					&& buf[num] != 'E' && buf[num] != '\n')
				return (0);
			increment_contains(&c, buf[num]);
		}
	}
	close(fd);
	return ((c.space < 1 || c.newline < 1 || c.wall < 1 ||
				c.player < 1 || c.exit < 1) ?
			ft_puterror("Incorrect file data...", 0) : 1);
}

char		**load_map(t_map *m, char *map_name, int fd, int i)
{
	char	*line;
	char	**array;

	if ((fd = open(map_name, O_RDONLY)) == -1)
		return (ft_putnull("Map open error... "));
	while (ft_gnl(fd, &line))
		m->max_h++;
	close(fd);
	if (!(array = (char **)malloc(sizeof(char *) * (m->max_h + 1))))
		return (ft_putnull("Failed to malloc appropriate map array..."));
	fd = open(map_name, O_RDONLY);
	while (ft_gnl(fd, &line))
		array[i++] = ft_strcpy(ft_strnew(ft_strlen(line)), line);
	array[i] = ft_strnew(0);
	close(fd);
	return (array);
}
