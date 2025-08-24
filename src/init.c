/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:21:50 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/19 17:39:34 by alicigar         ###   ########.fr       */
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

void	exit_game(t_game *g)
{
	mlx_destroy_image(g->mlx, g->wall->img);
	mlx_destroy_image(g->mlx, g->tile->img);
	mlx_destroy_image(g->mlx, g->p->img);
	mlx_destroy_image(g->mlx, g->e->img);
	mlx_destroy_image(g->mlx, g->c->img);
	mlx_destroy_window(g->mlx, g->window);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free_map(g->map);
	exit (0);
}

int	close_window(t_game *g)
{
	exit_game(g);
	return (0);
}
