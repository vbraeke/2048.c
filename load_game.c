/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/02/02 18:08:34 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/all.h"

int			**get_new_map(int len)
{
	int	**new;
	int	i;
	int y;
	int x;
	int	n;

	n = ft_rand();
	i = -1;
	new = (int **)malloc(sizeof(int *) * len);
	while (++i < len)
		new[i] = (int *)malloc(sizeof(int) * len);
	i = -1;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			new[y][x] = 0;
	}
	new[1][1] = n;
	return (new);
}

t_player	*load_player(int len)
{
	t_player *new;

	if (!(new = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	new->map = get_new_map(len);
	new->score = 0;
	new->key = 0;
	new->used = 1;
	new->win = 0;
	new->end = 0;
	new->size_map = len;
	new->tmp = NULL;
	return (new);
}

void		play_game(t_player *player)
{
	int		i;

	if (player->win == 0)
		check_win(player);
	player->tmp = map_cpy(player);
	replace_all(player);
	if (player->key == 65)
		sum_t(player);
	if (player->key == 66)
		sum_b(player);
	if (player->key == 67)
		sum_r(player);
	if (player->key == 68)
		sum_l(player);
	if ((i = map_comp(player)) == 1)
		ft_put_random(player);
	else if (i == 0 && player->used == player->size_map * player->size_map)
		player->end = 1;
}
