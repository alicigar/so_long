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

static void	count_lines(t_game *g, int fd)
{
	char	*line;

	g->map_height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		g->map_height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	fill_map(t_game *g, char *map_file)
{
	int		fd;
	int		y;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n map.ber not found\n");
		exit(1);
	}
	y = 0;
	while (y < g->map_height)
	{
		g->map[y] = get_next_line(fd);
		g->map[y] = ft_strtrim(g->map[y], "\n");
		if (!g->map[y])
			break ;
		y++;
	}
	g->map[y] = NULL;
	close(fd);
}

void	read_map(t_game *g, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0 || !map_file)
	{
		ft_printf("Error\n map.ber not found\n");
		exit(1);
	}
	count_lines(g, fd);
	close(fd);
	g->map = malloc(sizeof(char *) * (g->map_height + 1));
	if (!g->map)
	{
		ft_printf("Error\n");
		exit(1);
	}
	fill_map(g, map_file);
	if (g->map_height == 0 || !g->map[0])
	{
		ft_printf("Error\n The map is empty. \n");
		exit(1);
	}
	g->map_width = ft_strlen(g->map[0]);
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
	free(map);
}
