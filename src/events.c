/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:21:41 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/19 01:29:05 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	key_control(int keycode, t_game *g)
{
	if (keycode == 97 || keycode == 65361)
		step_p (g, -1, 0);
	if (keycode == 100 || keycode == 65363)
		step_p (g, 1, 0);
	if (keycode == 119 || keycode == 65362)
		step_p (g, 0, -1);
	if (keycode == 115 || keycode == 65364)
		step_p (g, 0, 1);
	if (keycode == 65307)
		exit_game(g);
	return (0);
}

void	count_collectibles(t_game *g)
{
	int		y;
	int		i;
	char	*row;
	char	*found;

	i = 0;
	y = 0;
	while (g->map[y])
	{
		row = g->map[y];
		found = ft_strchr(row, 'C');
		while (found)
		{
			i++;
			found++;
			found = ft_strchr(found, 'C');
		}
		y++;
	}
	g->c_count = i;
	g->collectibles = i;
}

static	void	update_p_pos(t_game *g, int new_p_x, int new_p_y)
{
	g->map[g->p_y][g->p_x] = '0';
	g->map[new_p_y][new_p_x] = 'P';
	g->p_x = new_p_x;
	g->p_y = new_p_y;
	g->step_counter++;
	ft_printf("Step: %d\n", g->step_counter);
	draw_base(g);
	draw_elements(g);
}

void	step_p(t_game *g, int step_x, int step_y)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = g->p_x + step_x;
	new_y = g->p_y + step_y;
	next_tile = g->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		g->collectibles--;
	if (next_tile == 'E')
	{
		if (g->collectibles == 0)
		{
			ft_printf("CONGRATULATIONS! You win the game <3\n");
			exit_game(g);
		}
		else
			return ;
	}
	update_p_pos(g, new_x, new_y);
}
