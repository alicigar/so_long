/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:12:17 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/20 01:11:38 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error! Invalid number of arguments. \n.");
		return (1);
	}
	init_game(&game);
	read_map(&game, argv[1]);
	find_player(game.map);
	if (!validate_map(&game, argv[1]))
	{
		free_map(game.map);
		return (1);
	}
	while (i < game.map_height)
	{
		ft_print_s(game.map[i]);
		ft_print_s("\n");
		i++;
	}
	free_map(game.map);
	return (0);
}
