/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 06:28:26 by tboivin           #+#    #+#             */
/*   Updated: 2017/03/25 23:39:18 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	stock_piece(char *line, t_fill *s)
{
	int y;

	y = 0;
	get_next_line(0, &line);
	if (!line || *line == '\0')
	{
		free(line);
		exit(0);
	}
	s->piece_y = ft_atoi(line + 6);
	s->piece_x = ft_atoi(line + 8);
	free(line);
	while (y != s->piece_y && get_next_line(0, &line) != -1)
	{
		ft_strcpy(s->piece[y], line);
		free(line);
		y++;
	}
	clean_line(s);
}

void	get_color(t_fill *s, char *map)
{
	int i;

	i = 0;
	usleep(500);
	while (map[i] != '\0')
	{
		if (map[i] == s->enemy)
		{
			ft_putstr_fd("\033[31m", 2);
			ft_putstr_fd("\033[41m", 2);
			ft_putchar_fd(s->enemy, 2);
			ft_putstr_fd("\033[0m", 2);
		}
		else if (map[i] == s->player)
		{
			ft_putstr_fd("\033[32m", 2);
			ft_putstr_fd("\033[42m", 2);
			ft_putchar_fd(s->player, 2);
			ft_putstr_fd("\033[0m", 2);
		}
		else
			get_color2();
		i++;
	}
}

void	get_map_(t_fill *s, char *line)
{
	int i;
	int color;

	color = COLOR;
	i = 0;
	while (i != s->size_y && get_next_line(0, &line))
	{
		ft_strcpy(s->map[i], line + 4);
		free(line);
		if (color == 1)
		{
			get_color(s, s->map[i]);
			ft_putendl_fd("", 2);
		}
		i++;
	}
	coord_enemy(s);
	coord_enemy2(s);
	get_coord(s);
	stock_piece(line, s);
}

void	get_map(t_fill *s, char *line)
{
	int y;
	int color;

	color = COLOR;
	y = 0;
	get_next_line(0, &line);
	if (!line || *line == '\0')
	{
		free(line);
		exit(0);
	}
	s->size_y = ft_atoi(&line[8]);
	s->size_x = ft_atoi(&line[11]);
	free(line);
	get_next_line(0, &line);
	free(line);
	if (color == 1)
		ft_putstr_fd("\x1B[0;0H", 2);
	get_map_(s, line);
}
