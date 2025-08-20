/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:35:11 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/19 01:21:35 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extension(char *map_file)
{
	char	*d;

	d = ft_strrchr(map_file, '.');
	if (!d || d[1] != 'b' || d[2] != 'e' || d[3] != 'r' || d[4] != '\0')
		return (0);
	return (1);
}

int	check_valid_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'P' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->p_count = 0;
	game->e_count = 0;
	game->c_count = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->p_count++;
			else if (game->map[i][j] == 'E')
				game->e_count++;
			else if (game->map[i][j] == 'C')
				game->c_count++;
			j++;
		}
		i++;
	}
	if (game->p_count != 1 || game->e_count < 1 || game->c_count < 1)
		return (0);
	return (1);
}

int	check_rectangular(t_game *game)
{
	int		i;
	size_t	width;

	if (game->map_height == 0 || !game->map[0])
		return (ft_printf("Error: Map is empty\n"), 0);
	width = ft_strlen(game->map[0]);
	i = 1;
	while (i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}
