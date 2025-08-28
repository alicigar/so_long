/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:35:11 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/28 20:05:29 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extension(t_game *g, char *argv)
{
	char	*d;

	d = ft_strrchr(argv, '.');
	if (!d || d[1] != 'b' || d[2] != 'e' || d[3] != 'r' || d[4] != '\0')
	{
		ft_printf("Error\nThe extension is invalid\n");
		free_map(g->map);
		exit(1);
	}
	return (1);
}

int	check_valid_chars(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map_height)
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] != '0' && g->map[i][j] != '1' &&
				g->map[i][j] != 'P' && g->map[i][j] != 'E' &&
				g->map[i][j] != 'C')
			{
				ft_printf("Error\nThere is an invalid char\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_elements(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < g->map_height)
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
				g->p_count++;
			else if (g->map[i][j] == 'E')
				g->e_count++;
			else if (g->map[i][j] == 'C')
				g->c_count++;
			j++;
		}
		i++;
	}
	if (g->p_count != 1 || g->e_count != 1 || g->c_count < 1)
	{
		ft_printf("Error\nInvalid number of elements\n");
		return (0);
	}
	return (1);
}

int	check_rectangular(t_game *g)
{
	int		i;
	size_t	width;

	if (g->map_height == 0 || !g->map[0])
	{
		ft_printf("Error\nThe map is empty\n");
		return (0);
	}
	width = ft_strlen(g->map[0]);
	i = 1;
	while (i < g->map_height)
	{
		if (ft_strlen(g->map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *g)
{
	int		x;
	int		y;

	x = 0;
	while (x < g->map_height)
	{
		if (g->map[x][0] != '1' || g->map[x][g->map_width - 1] != '1')
		{
			ft_printf("Error\nWall is missing in row\n", x);
			return (0);
		}
		x++;
	}
	y = 0;
	while (y < g->map_width)
	{
		if (g->map[0][y] != '1' || g->map[g->map_height - 1][y] != '1')
		{
			ft_printf("Error\nWall is missing in column\n", y);
			return (0);
		}
		y++;
	}
	return (1);
}
