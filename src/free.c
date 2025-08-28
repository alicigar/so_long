/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:28:01 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/28 15:12:29 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	free_map_and_e(char **copy, t_game *g, char *str)
{
	free_map(copy);
	free_map(g->map);
	ft_printf("%s\n", str);
	exit(1);
}

void	free_images(t_game *g)
{
	if (g->wall)
		free(g->wall);
	if (g->tile)
		free(g->tile);
	if (g->p)
		free(g->p);
	if (g->e)
		free(g->e);
	if (g->c)
		free(g->c);
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
	free_images(g);
	free_map(g->map);
	exit (0);
}
