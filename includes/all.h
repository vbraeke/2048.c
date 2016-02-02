/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:10:29 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/31 21:29:05 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include <ncurses.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct		s_player
{
	int				end;
	int				used;
	int				tools;
	int				win;
	int				**map;
	int				**tmp;
	int				size_map;
	int				score;
	int				key;
}					t_player;

void				print_cols(void);
void				print_lines(void);
void				print_score(t_player *map);
void				print_map(t_player *player);
void				replace_l(t_player *map, int i, int j);
void				replace_r(t_player *map, int i, int j);
void				replace_t(t_player *map, int i, int j);
void				replace_b(t_player *map, int i, int j);
void				replace_all(t_player *map);
void				replace_all_l(t_player *map);
void				replace_all_r(t_player *map);
void				replace_all_b(t_player *map);
void				replace_all_t(t_player *map);
void				sum_l(t_player *map);
void				sum_r(t_player *map);
void				sum_t(t_player *map);
void				sum_b(t_player *map);
void				ft_put_random(t_player *player);
void				play_game(t_player *player);
void				printmap(int **map);
void				check_win(t_player *map);
void				ft_win(t_player *map);

int					ft_rand(void);
int					main(void);
int					play(t_player *player);
int					get_next_key(void);
int					**get_new_map(int len);
int					**map_cpy(t_player *player);
int					map_comp(t_player *player);

t_player			*load_player(int len);

#endif
