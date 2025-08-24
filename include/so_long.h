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

# define TILE_SIZE 64

typedef struct t_img
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
	t_img	*tile;
	t_img	*p;
	t_img	*e;
	t_img	*c;
	int		map_width;
	int		map_height;
	int		p_count;
	int		e_count;
	int		c_count;
	int		collectibles;
	int		p_x;
	int		p_y;
	int		step_counter;
}	t_game;

typedef struct s_map
{
	int		x;
	int		y;
}	t_coord;

void	init_game(t_game *g);
void	read_map(t_game *g, char *map_file);
void	free_map(char **map);
int		check_extension(char *map_file);
int		check_valid_chars(t_game *g);
int		check_elements(t_game *g);
int		check_rectangular(t_game *g);
int		check_walls(t_game *g);
int		check_path(t_game *g);
int		validate_map(t_game *g, char *filename);
void	init_images(t_game *g);
void	init_window(t_game *g);
void	load_img(t_game *g);
void	draw_base(t_game *g);
void	draw_elements(t_game *g);
int		key_control(int keycode, t_game *g);
void	set_p_pos(t_game *g);
void	count_collectibles(t_game *g);
void	step_p(t_game *g, int step_x, int step_y);
void	exit_game(t_game *g);
int		close_window(t_game *g);

#endif
