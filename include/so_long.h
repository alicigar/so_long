/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:23:27 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/20 00:24:35 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"

typedef struct s_point
{
	void	*img;
	int		x;
	int		y;
}		t_img;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*window;
	t_img	*wall;
	t_img	*ground;
	t_img	*p;
	t_img	*e;
	t_img	*c;
	int		map_width;
	int		map_height;
	int		p_count;
	int		e_count;
	int		c_count;
}	t_game;

typedef struct s_map
{
	int		x;
	int		y;
}	t_coord;


void	init_game(t_game *game);
void	read_map(t_game *game, char *map_file);
void	free_map(char **map);
int		check_extension(char *map_file);
int		check_valid_chars(t_game *game);
int		check_elements(t_game *game);
int		check_rectangular(t_game *game);
int		checkwall(t_game *game);
int		validate_map(t_game *game, char *filename);
t_coord	*find_player(char **map);
int		ff_preview(t_game *game);
int		map_cmp(t_game *game, char **copy);

#endif
