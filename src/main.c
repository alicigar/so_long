/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:12:17 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/27 09:06:27 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	init_game(&g);
	reading_map(&g, argv[1]);
	if (!validate_map(&g, argv[1]))
	{
		free_map(g.map);
		return (1);
	}
	set_p_pos(&g);
	count_collectibles(&g);
	init_window(&g);
	init_images(&g);
	load_img(&g);
	draw_base(&g);
	draw_elements(&g);
	mlx_key_hook(g.window, key_control, &g);
	mlx_hook(g.window, 17, 0, close_window, &g);
	mlx_loop(g.mlx);
	return (0);
}
