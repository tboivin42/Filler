/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 23:18:17 by tboivin           #+#    #+#             */
/*   Updated: 2017/02/22 23:18:19 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_fill	*set_struct(void)
{
	t_fill *s;

	if (!(s = (t_fill *)malloc(sizeof(t_fill))))
		return (NULL);
	s->d_line = 0;
	s->player = 0;
	s->enemy = 0;
	s->d_line = 0;
	s->size_y = 0;
	s->size_x = 0;
	s->piece_y = 0;
	s->piece_x = 0;
	return (s);
}

void	free_lst(t_lt **f)
{
	t_lt *tmp;

	while (*f)
	{
		tmp = *f;
		*f = (*f)->next;
		free(tmp);
	}
	free(*f);
}

int		main(void)
{
	char	*line;
	int		color;
	t_fill	*s;
	t_lt	*f;

	color = COLOR;
	f = NULL;
	s = set_struct();
	get_next_line(0, &line);
	s->player = (ft_strncmp(line, "$$$ exec p1", 11) == 0) ? 'O' : 'X';
	s->enemy = (s->player == 'O') ? 'X' : 'O';
	free(line);
	if (color == 1)
	{
		ft_putstr_fd("\e[?25l", 2);
		ft_putstr_fd("\e[1;1H\e[2J", 2);
	}
	while (1)
	{
		get_map(s, line);
		begin(f, s);
	}
	return (0);
}
