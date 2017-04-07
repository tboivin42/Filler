/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 23:36:59 by tboivin           #+#    #+#             */
/*   Updated: 2017/03/26 23:37:03 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	clean_line3(t_fill *s)
{
	int y;
	int x;
	int g;

	y = s->piece_y - 1;
	while (y > 0)
	{
		g = 0;
		x = s->piece_x;
		while (x > 0)
		{
			if (s->piece[y][x] == '*')
			{
				s->piece_x -= g;
				return ;
			}
			g++;
			x--;
		}
		y--;
	}
}

void	clean_line2(t_fill *s)
{
	int y;
	int x;
	int i;

	s->d_line = s->piece_x;
	i = 0;
	y = 0;
	while (y < s->piece_y)
	{
		x = 0;
		while (x < s->piece_x)
		{
			if (s->piece[y][x] == '*')
			{
				if (x < s->d_line)
					s->d_line = x;
			}
			x++;
		}
		y++;
	}
}

void	clean_columns(t_fill *s)
{
	int i;
	int h;

	s->column = 0;
	h = 0;
	i = 0;
	while (i < s->piece_y)
	{
		if (ft_strchr(s->piece[i], '*'))
			h = 1;
		if (h == 0)
			s->column++;
		i++;
	}
	i = s->piece_y - 1;
	h = 0;
	while (i > 0)
	{
		if (ft_strchr(s->piece[i], '*'))
			h = 1;
		if (h == 0)
			s->piece_y--;
		i--;
	}
}

void	clean_line(t_fill *s)
{
	int i;
	int y;

	i = 0;
	y = 0;
	clean_line2(s);
	clean_columns(s);
	s->column = 0;
}
