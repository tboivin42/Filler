/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 01:10:14 by tboivin           #+#    #+#             */
/*   Updated: 2017/03/23 01:10:16 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	d_right(t_fill *s, t_lt *f)
{
	int		y;
	int		x;
	t_lt	*tmp;

	tmp = f;
	(void)s;
	x = 0;
	y = 0;
	while (tmp)
	{
		if (y < tmp->y)
			y = tmp->y;
		tmp = tmp->next;
	}
	tmp = f;
	while (tmp)
	{
		if (y == tmp->y)
		{
			if (x < tmp->x)
				x = tmp->x;
		}
		tmp = tmp->next;
	}
	// ft_dprintf(2, "column: %d line: %d y: %d x: %d\n", s->column, s->d_line, y, x);
	// ft_dprintf(2, "D_right y : %d x : %d\n", s->column - y, s->d_line - x);
	ft_printf("%d %d\n", y, x);
}

void	d_left(t_fill *s, t_lt *f)
{
	int		y;
	int		x;
	t_lt	*tmp;

	tmp = f;
	x = s->size_x;
	y = 0;
	while (tmp)
	{
		if (y < tmp->y)
			y = tmp->y;
		tmp = tmp->next;
	}
	tmp = f;
	while (tmp)
	{
		if (y == tmp->y)
		{
			if (x > tmp->x)
				x = tmp->x;
		}
		tmp = tmp->next;
	}
	// ft_dprintf(2, "d_left : [%d %d]\n", s->column + y, x + s->d_line);
	ft_printf("%d %d\n", y, x);
}

void	h_right(t_fill *s, t_lt *f)
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
		if (y == tmp->y)
		{
			if (x < tmp->x)
				x = tmp->x;
		}
		tmp = tmp->next;
	}
	// ft_dprintf(2, "h_right : [%d %d]\n",/* s->column + */y, x/* + s->d_line*/);
	ft_printf("%d %d\n", y, x);
}

void	down_right(t_fill *s, t_lt *f)
{
	int		y;
	int		x;
	t_lt	*tmp;

	tmp = f;
	(void)s;
	x = 0;
	y = 0;
	while (tmp)
	{
		if (y < tmp->y)
			y = tmp->y;
		tmp = tmp->next;
	}
	tmp = f;
	while (tmp)
	{
		if (y == tmp->y)
		{
			if (x < tmp->x)
				x = tmp->x;
		}
		tmp = tmp->next;
	}
	if (s->player_y_d == s->size_y && (s->player_x_r + 1 == s->size_x
		|| s->player_x_l == 0))
		h_right(s, f);
	else if (s->player_y_h == 0 && (s->player_x_r + 1 == s->size_x
		|| s->player_x_l == 0))
		d_left(s, f);
	else
		ft_printf("%d %d\n", y, x);
}

void	h_left(t_fill *s, t_lt *f)
{
	int		y;
	int		x;
	t_lt	*tmp;

	tmp = f;
	x = s->size_x;
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
		if (y == tmp->y && x > tmp->x)
			x = tmp->x;
		// else
		// 	break ;
		tmp = tmp->next;
	}
	if (s->player_y_h == 0 && (s->player_x_l != 0
		|| s->player_y_d < s->enemy_y_h))
		d_right(s, f);
	else if (s->player_y_d == s->size_y && s->player_x_l == 0
		&& s->player_y_h == 0 && s->player_x_r == s->size_x)
		d_left(s, f);
	else if (s->player_y_d == s->size_y && (s->player_x_l == 0
		|| s->player_x_r == s->size_x))
		h_right(s, f);
	else
		ft_printf("%d %d\n", y - s->column, x - s->column);
}
