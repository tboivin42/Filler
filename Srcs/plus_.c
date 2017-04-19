/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:58:50 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/13 22:58:53 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_color2(void)
{
	ft_putstr_fd("\033[30m", 2);
	ft_putchar_fd('.', 2);
	ft_putstr_fd("\033[0m", 2);
}

void	suite(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	right(t_lt *f)
{
	int		y;
	int		x;
	t_lt	*tmp;

	tmp = f;
	x = 0;
	y = 0;
	while (tmp)
	{
		if (x < tmp->x)
			x = tmp->x;
		tmp = tmp->next;
	}
	tmp = f;
	while (tmp)
	{
		if (x == tmp->x)
			y = tmp->y;
		tmp = tmp->next;
	}
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	left(t_fill *s, t_lt *f)
{
	int		y;
	int		x;
	t_lt	*tmp;

	tmp = f;
	x = s->size_x;
	y = 0;
	while (tmp)
	{
		if (x > tmp->x)
			x = tmp->x;
		tmp = tmp->next;
	}
	tmp = f;
	while (tmp)
	{
		if (x == tmp->x)
			y = tmp->y;
		tmp = tmp->next;
	}
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	map_2(t_fill *s, t_lt *f)
{
	if (s->player_y_h > s->enemy_y_h && s->player_x_l > s->enemy_x_l)
		h_left(s, f);
	else if (s->player_y_h == 0 && s->player_y_d == s->size_y
		&& s->player_x_l == 0 && s->player_x_r + 1 == s->size_x)
		left(s, f);
	else if (s->player_y_h < s->enemy_y_h && s->player_y_d != s->size_y)
		d_right(s, f);
	else if (s->player_y_h - s->enemy_y_d < 20 && s->player_x_l != 0)
		left(s, f);
	else if (s->player_y_h == 0 || (s->enemy_x_l == 0
		&& s->enemy_x_r + 1 == s->size_x))
		h_left(s, f);
	else if (s->player_x_l == 0)
		right(f);
	else
		right(f);
}
