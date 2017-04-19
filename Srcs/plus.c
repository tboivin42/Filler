/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 01:49:51 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/07 01:49:53 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	down_right_(t_fill *s, t_lt *f, int y, int x)
{
	if (s->player_x_r + 1 == s->size_x)
		h_right(s, f);
	else
	{
		ft_putnbr(y);
		ft_putchar(' ');
		ft_putnbr(x);
		ft_putchar('\n');
	}
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
			if (s->map[y - 1][x] == s->enemy)
			{
				s->enemy_y_d = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

void	map_01(t_fill *s, t_lt *f, int y, int x)
{
	if ((s->player_y_d == s->size_y && s->player_x_r + 1 == s->size_x)
		|| s->player_y_h - s->enemy_y_d == 3)
		h_left(s, f);
	else if (s->player_y_h == 0 && (s->player_x_r + 1 == s->size_x
		|| s->player_x_l == 0))
		d_left(s, f);
	else
	{
		ft_putnbr(y);
		ft_putchar(' ');
		ft_putnbr(x);
		ft_putchar('\n');
	}
}

void	map_0(t_fill *s, t_lt *f)
{
	int		y;
	int		x;
	t_lt	*tmp;

	tmp = f;
	x = 0;
	y = s->size_y;
	while (tmp)
	{
		if (y > tmp->y)
			y = tmp->y;
		tmp = tmp->next;
	}
	tmp = f;
	while (tmp)
	{
		if (y == tmp->y && x < tmp->x)
			x = tmp->x;
		tmp = tmp->next;
	}
	map_01(s, f, y, x);
}

void	h_left_(t_fill *s, t_lt *f, int y, int x)
{
	if ((s->player_y_h == 0 && (s->player_x_l != 0
		|| s->player_y_d < s->enemy_y_h)) || (s->player_y_d - s->enemy_y_d < 3))
		d_left(s, f);
	else if (s->player_y_d == s->size_y)
		h_right(s, f);
	else
	{
		ft_putnbr(y);
		ft_putchar(' ');
		ft_putnbr(x);
		ft_putchar('\n');
	}
}
