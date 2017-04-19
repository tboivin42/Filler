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
		if (y == tmp->y && x < tmp->x)
			x = tmp->x;
		tmp = tmp->next;
	}
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
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
		if (y == tmp->y && x > tmp->x)
			x = tmp->x;
		tmp = tmp->next;
	}
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
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
		if (y == tmp->y && x < tmp->x)
			x = tmp->x;
		tmp = tmp->next;
	}
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
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
		if (y == tmp->y && x < tmp->x)
			x = tmp->x;
		tmp = tmp->next;
	}
	down_right_(s, f, y, x);
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
		tmp = tmp->next;
	}
	if (s->size_y < 20)
		h_left_(s, f, y, x);
	else
		suite(y, x);
}
