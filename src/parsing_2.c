/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:36:51 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/20 01:21:16 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_walls(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < game->map_height)
	{
		if (game->map[x][0] != '1' || game->map[x][game->map_width - 1] != '1')
		{
			ft_printf("Error: Wall is missing in row\n", x);
			return (0);
		}
		x++;
	}
	y = 0;
	while (y < game->map_width)
	{
		if (game->map[0][y] != '1' || game->map[game->map_height - 1][y] != '1')
		{
			ft_printf("Error: Wall is missing in column\n", y);
			return (0);
		}
		y++;
	}
	return (1);
}

t_coord	*find_player(char **map)
{
	t_coord	*player_pos;

	player_pos = NULL;
	player_pos = malloc(sizeof(t_coord *));
	player_pos->x = 0;
	while (map[player_pos->x])
	{
		player_pos->y = 0;
		while (map[player_pos->x][player_pos->y])
		{
			if (map[player_pos->x][player_pos->y] == 'P')
				return (player_pos);
			player_pos->y++;
		}
		player_pos->x++;
	}
	return (NULL);
}

int	ff_preview(t_game *game)
{
	char	**copy;
	int		i;
	t_coord	*player_pos;

	i = 0;
	copy = malloc(sizeof(char *) * (game->map_height + 1));
	while (game->map[i])
	{
		copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	player_pos = find_player(game->map);
	if (!map_cmp(game, copy))
	{
		free_map(copy);
		return (0);
	}
	free_map(copy);
	return (1);
}

int	map_cmp(t_game *game, char **copy)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if ((game->map[x][y] == 'C' || game->map[x][y] == 'E') \
&& copy[x][y] != 'F')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	validate_map(t_game *game, char *argv)
{
	if (!check_extension(argv))
		return (ft_printf("Error: Invalid extension\n"), 0);
	else if (!check_valid_chars(game))
		return (ft_printf("Error: Invalid character\n"), 0);
	else if (!check_elements(game))
		return (ft_printf("Error: Wrong element\n"), 0);
	else if (!check_rectangular(game))
		return (ft_printf("Error: Map is not rectangular\n"), 0);
	else if (!check_walls(game))
		return (ft_printf("Error: Map is not surrounded by walls\n"), 0);
	return (1);
}
