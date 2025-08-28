/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 04:06:21 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/28 20:06:45 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_coord	*find_player(char **map)
{
	t_coord	*p_pos;

	p_pos = malloc(sizeof(t_coord));
	if (!p_pos)
		return (NULL);
	p_pos->x = 0;
	while (map[p_pos->x])
	{
		p_pos->y = 0;
		while (map[p_pos->x][p_pos->y])
		{
			if (map[p_pos->x][p_pos->y] == 'P')
				return (p_pos);
			p_pos->y++;
		}
		p_pos->x++;
	}
	free(p_pos);
	return (NULL);
}

static int	map_cmp(t_game *g, char **copy)
{
	int	x;
	int	y;

	x = 0;
	while (g->map[x])
	{
		y = 0;
		while (g->map[x][y])
		{
			if ((g->map[x][y] == 'C' || g->map[x][y] == 'E') \
&& copy[x][y] != 'F')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static void	flood_fill(char **map, t_coord p_pos)
{
	if (map[p_pos.x][p_pos.y] == 'E')
	{
		map[p_pos.x][p_pos.y] = 'F';
		return ;
	}
	if (p_pos.x < 0 || p_pos.y < 0 || !map[p_pos.x] || !map[p_pos.x][p_pos.y] || \
map[p_pos.x][p_pos.y] == '1' || map[p_pos.x][p_pos.y] == 'F')
		return ;
	map[p_pos.x][p_pos.y] = 'F';
	flood_fill(map, (t_coord){p_pos.x - 1, p_pos.y});
	flood_fill(map, (t_coord){p_pos.x, p_pos.y + 1});
	flood_fill(map, (t_coord){p_pos.x + 1, p_pos.y});
	flood_fill(map, (t_coord){p_pos.x, p_pos.y - 1});
}

int	check_path(t_game *g)
{
	char	**copy;
	int		i;
	t_coord	*p_pos;

	copy = malloc(sizeof(char *) * (g->map_height + 1));
	if (!copy)
		return (0);
	i = 0;
	while (g->map[i])
	{
		copy[i] = ft_strdup(g->map[i]);
		if (!copy[i])
			free_map_and_e(copy, g, "Error\nThe map is not playable");
		i++;
	}
	copy[i] = NULL;
	p_pos = find_player(copy);
	if (!p_pos)
		free_map_and_e(copy, g, "Error\nThere is not player");
	flood_fill(copy, *p_pos);
	free(p_pos);
	if (!map_cmp(g, copy))
		free_map_and_e(copy, g, "Error\nThe map is not playable");
	free_map(copy);
	return (1);
}

int	validate_map(t_game *g, char *argv)
{
	if (!check_path(g) || !check_extension(g, argv) || !check_valid_chars(g) \
|| !check_elements(g) || !check_rectangular(g) \
|| !check_walls(g))
		return (0);
	return (1);
}
