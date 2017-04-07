/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 00:56:04 by tboivin           #+#    #+#             */
/*   Updated: 2017/03/28 00:56:05 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_coord_y2(t_fill *s)
{
	int x;
	int y;

	y = s->size_y;
	while (y > 0)
	{
		x = s->size_x;
		while (x > 0)
		{
			if (s->map && s->map[y - 1][x] == s->player)
			{
				s->player_y_d = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

void	get_coord_y(t_fill *s)
{
	int x;
	int y;

	y = 0;
	get_coord_y2(s);
	while (y < s->size_y && s->map[y])
	{
		x = 0;
		while (x < s->size_x && s->map[y][x] != '\0')
		{
			if (s->map[y][x] == s->player)
			{
				s->player_y_h = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_coord(t_fill *s)
{
	int x;
	int y;

	s->player_x_l = s->size_x;
	s->player_x_r = 0;
	y = 0;
	while (y < s->size_y && s->map[y])
	{
		x = 0;
		while (x < s->size_x && s->map[y][x] != '\0')
		{
			if (s->player_x_l > x && s->map[y][x] == s->player)
				s->player_x_l = x;
			if (s->player_x_r < x && s->map[y][x] == s->player)
				s->player_x_r = x;
			x++;
		}
		y++;
	}
	get_coord_y(s);
}

void	coord_enemy3(t_fill *s)
{
	int x;
	int y;

	y = s->size_y;
	while (y > 0)
	{
		x = s->size_x;
		while (x > 0)
		{
			if (s->map && s->map[y - 1][x] == s->enemy)
			{
				s->enemy_y_d = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

void	coord_enemy2(t_fill *s)
{
	int x;
	int y;

	s->enemy_x_l = s->size_x;
	s->enemy_x_r = 0;
	y = 0;
	while (y < s->size_y && s->map[y])
	{
		x = 0;
		while (x < s->size_x && s->map[y][x] != '\0')
		{
			if (s->enemy_x_l > x && s->map[y][x] == s->enemy)
				s->enemy_x_l = x;
			if (s->enemy_x_r < x && s->map[y][x] == s->enemy)
				s->enemy_x_r = x;
			x++;
		}
		y++;
	}
}

void	coord_enemy(t_fill *s)
{
	int x;
	int y;

	y = 0;
	coord_enemy3(s);
	while (y < s->size_y && s->map[y])
	{
		x = 0;
		while (x < s->size_x && s->map[y][x] != '\0')
		{
			if (s->map[y][x] == s->enemy)
			{
				s->enemy_y_h = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
