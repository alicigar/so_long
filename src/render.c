/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:02:56 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/24 18:47:02 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_img(t_game *g)
{
	int	w;
	int	h;

	g->wall->img = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
	g->tile->img = mlx_xpm_file_to_image(g->mlx, "textures/tile.xpm", &w, &h);
	g->p->img = mlx_xpm_file_to_image(g->mlx, "textures/p.xpm", &w, &h);
	g->e->img = mlx_xpm_file_to_image(g->mlx, "textures/e.xpm", &w, &h);
	g->c->img = mlx_xpm_file_to_image(g->mlx, "textures/c.xpm", &w, &h);
	if (!g->wall->img || !g->tile->img || !g->p->img || \
!g->e->img || !g->c->img)
	{
		ft_printf("Error\nImages are not loading.\n");
		exit(1);
	}
}

static void	draw_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->window, img, \
x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_base(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				draw_tile(g, g->tile->img, x, y);
			if (g->map[y][x] == '0')
				draw_tile(g, g->tile->img, x, y);
			if (g->map[y][x] == 'P')
				draw_tile(g, g->tile->img, x, y);
			if (g->map[y][x] == 'E')
				draw_tile(g, g->tile->img, x, y);
			if (g->map[y][x] == 'C')
				draw_tile(g, g->tile->img, x, y);
			x++;
		}
		y++;
	}
}

void	draw_elements(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				draw_tile(g, g->wall->img, x, y);
			if (g->map[y][x] == 'P')
				draw_tile(g, g->p->img, x, y);
			if (g->map[y][x] == 'E')
				draw_tile(g, g->e->img, x, y);
			if (g->map[y][x] == 'C')
				draw_tile(g, g->c->img, x, y);
			x++;
		}
		y++;
	}
}
