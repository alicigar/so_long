/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:14:24 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/19 23:37:42 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	count_lines(t_game *game, int fd)
{
	char	*line;

	game->map_height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	fill_map(t_game *game, char *map_file)
{
	int		fd;
	int		y;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: map.ber not found\n");
		exit(1);
	}
	y = 0;
	while (y < game->map_height)
	{
		game->map[y] = get_next_line(fd);
		game->map[y] = ft_strtrim(game->map[y], "\n");
		if (!game->map[y])
			break ;
		y++;
	}
	game->map[y] = NULL;
	close(fd);
}

void	read_map(t_game *game, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0 || !map_file)
	{
		ft_printf("Error: map.ber not found\n");
		exit(1);
	}
	count_lines(game, fd);
	close(fd);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
	{
		ft_printf("Error\n");
		exit(1);
	}
	fill_map(game, map_file);
	if (game->map_height == 0 || !game->map[0])
	{
		ft_printf("Error: empty map\n");
		exit(1);
	}
	game->map_width = ft_strlen(game->map[0]);
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map[y]);
}
