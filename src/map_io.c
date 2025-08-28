/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:14:24 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/28 17:04:39 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	if (!line)
	{
		perror ("Error\nThe map is empty\n");
		exit(1);
	}
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

static char	*search_and_replace(char *str, char a, char b)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		i++;
	}
	return (str);
}

static	void	fill_map(t_game *g, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < g->map_height)
	{
		g->map[i] = search_and_replace(line, '\n', '\0');
		i++;
		line = get_next_line(fd);
	}
	g->map[i] = NULL;
}

void	reading_map(t_game *g, char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMissing or invalid file\n");
		free_map(g->map);
		free(g);
		exit(1);
	}
	g->map_height = count_lines(fd);
	close(fd);
	fd = open(map_file, O_RDONLY);
	g->map = malloc(sizeof(char *) * (g->map_height + 1));
	if (!g->map)
	{
		ft_printf("Error\nMemory allocation failed\n");
		exit(1);
	}
	fill_map(g, fd);
	g->map_width = ft_strlen(g->map[0]);
	close(fd);
}
