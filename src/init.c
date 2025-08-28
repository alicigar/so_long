/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:21:50 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/28 17:05:23 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *g)
{
	g->map = NULL;
	g->mlx = NULL;
	g->window = NULL;
	g->wall = 0;
	g->tile = 0;
	g->p = 0;
	g->e = 0;
	g->c = 0;
	g->map_width = 0;
	g->map_height = 0;
	g->p_count = 0;
	g->e_count = 0;
	g->c_count = 0;
	g->collectibles = 0;
	g->p_x = 0;
	g->p_y = 0;
	g->step_counter = 0;
}

void	set_p_pos(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
			{
				g->p_x = x;
				g->p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_window(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		ft_printf("Error\n Initialization has failed.\n");
		exit(1);
	}
	g->window = mlx_new_window(g->mlx, g->map_width * TILE_SIZE, \
g->map_height * TILE_SIZE, "so_long");
	if (!g->window)
	{
		ft_printf("Error\n mlx_new_window has failed.\n");
		exit(1);
	}
}

void	init_images(t_game *g)
{
	g->wall = malloc(sizeof(t_img));
	g->tile = malloc(sizeof(t_img));
	g->p = malloc(sizeof(t_img));
	g->e = malloc(sizeof(t_img));
	g->c = malloc(sizeof(t_img));
	if (!g->wall || !g->tile || !g->p || !g->e || !g->c)
	{
		ft_printf("Error\n Memory allocation has failed.\n");
		exit(1);
	}
}
