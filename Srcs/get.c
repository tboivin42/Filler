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
	s->piece_y = ft_atoi(&line[6]);
	s->piece_x = ft_atoi(&line[8]);
	while (y != s->piece_y && get_next_line(0, &line) != -1)
	{
		ft_strcpy(s->piece[y], line);
		y++;
	}
	clean_line(s);
}

void	get_color(t_fill *s, char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == s->enemy)
		{
			ft_putstr_fd("\033[31m", 2);
			ft_putchar_fd(s->enemy, 2);
			ft_putstr_fd("\033[0m", 2);
		}
		else if (map[i] == s->player)
		{
			ft_putstr_fd("\033[32m", 2);
			ft_putchar_fd(s->player, 2);
			ft_putstr_fd("\033[0m", 2);
		}
		else
		{
			ft_putstr_fd("\033[28m", 2);
			ft_putchar_fd('.', 2);
			ft_putstr_fd("\033[0m", 2);
		}
		i++;
	}
}

void	get_map(t_fill *s, char *line)
{
	int y;
	int i;
	int c;

	s->i = 0;
	i = 0;
	c = 0;
	y = 0;
	get_next_line(0, &line);
	s->size_y = ft_atoi(&line[8]);
	s->size_x = ft_atoi(&line[11]);
	get_next_line(0, &line);
	if (!(s->map = (char**)malloc(sizeof(char*) * s->size_x + 1)))
		return ;
	if (color == 1)
		ft_putendl_fd("\n\n\n", 2);
	while (i != s->size_y && get_next_line(0, &line))
	{
		s->map[i] = line + 4;
		if (color == 1)
		{
			get_color(s, s->map[i]);
			ft_putendl_fd("", 2);
		}
		i++;
	}
	if (color == 1)
		ft_putendl_fd("\n\n\n", 2);
	coord_enemy(s);
	coord_enemy2(s);
	get_coord(s);
	stock_piece(line, s);
}
