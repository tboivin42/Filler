/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 23:19:19 by tboivin           #+#    #+#             */
/*   Updated: 2017/02/22 23:19:20 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define color 0
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct		s_fill
{
	char			player;
	char			enemy;
	char			**map;
	int				tot;
	int				dot;
	int				d_line;
	int				nb_piece;
	int				player_y_d;
	int				player_y_h;
	int				player_x_r;
	int				player_x_l;
	int				column;
	int				y;
	int				i;
	int				x;
	int				enemy_y_h;
	int				enemy_y_d;
	int				enemy_x_r;
	int				enemy_x_l;
	int				size_y;
	int				size_x;
	int				piece_y;
	int				piece_x;
	char			piece[100][100];
}					t_fill;

typedef struct		s_lt
{
	int				y;
	int				x;
	struct s_lt		*next;
}					t_lt;

void				d_left(t_fill *s, t_lt *f);
void				map_0(t_fill *s, t_lt *f);
void				down_right(t_fill *s, t_lt *f);
void				d_right(t_fill *s, t_lt *f);
void				clean_line(t_fill *s);
void				get_coord(t_fill *s);
void				coord_enemy2(t_fill *s);
void				coord_enemy(t_fill *s);
void				clean_columns(t_fill *s);
void				h_right(t_fill *s, t_lt *f);
void				h_left(t_fill *s, t_lt *f);
void				get_map(t_fill *s, char *line);
void				start(t_fill *s);
void				begin(t_lt *f, t_fill *s);
void				begin2(t_lt *f, t_fill *s);
void				begin3(t_fill *s);

#endif
