/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 04:52:50 by tboivin           #+#    #+#             */
/*   Updated: 2017/03/09 04:52:52 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_lt	*create(int y, int x)
{
	t_lt *new;

	if (!(new = (t_lt*)malloc(sizeof(t_lt))))
		return (NULL);
	new->y = y;
	new->x = x;
	new->next = NULL;
	return (new);
}

int		possible(t_fill *s, int y, int x)
{
	int py;
	int px;
	int touch;

	touch = 0;
	py = s->column;
	while (py < s->piece_y && s->map[y + py] && y + s->piece_y <= s->size_y)
	{
		px = s->d_line;
		while (px < s->piece_x && s->map[y + py][x + px]
			&& x + s->piece_x <= s->size_x)
		{
			if (touch > 1)
				return (0);
			if (s->map[y + py][x + px] == s->player && s->piece[py][px] == '*')
			{
				touch++;
			}
			else if (s->map[y + py][x + px] == s->enemy)
				return (0);
			px++;
		}
		py++;
	}
	if (touch == 1)
		return (1);
	else
		return (0);
}

void	add_back(t_lt **f, int y, int x)
{
	t_lt *tmp;

	tmp = (*f);
	if (!(*f))
	{
		(*f) = create(y, x);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create(y, x);
}

void	begin(t_lt *f, t_fill *s)
{
	int y;
	int x;

	y = 0;
	while (y < s->size_y)
	{
		x = 0;
		while (s->map[y][x] && x < s->size_x)
		{
			if (possible(s, y, x) == 1)
				add_back(&f, y, x);
			x++;
		}
		y++;
	}
	if (f)
	{
		if (s->player_y_h < s->enemy_y_h && s->player_y_d != 0)
		{
			if (s->size_y < 20)
				map_0(s, f);
			else
				down_right(s, f);
		}
		else
			h_left(s, f);
	}
	else
		exit(0);
}
