/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:07:35 by tmerida-          #+#    #+#             */
/*   Updated: 2022/11/19 11:26:15 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft.h"
# include "./get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>

# define SIZE_TEXTURE 100

# define WIDTH 1920
# define HEIGHT 1080
# define KEY_UP					13
# define KEY_DOWN				1
# define KEY_RIGHT				2
# define KEY_LEFT				0
# define KEY_RIGHT_VISION		124
# define KEY_LEFT_VISION		123
# define ESCAPE					53

typedef struct s_corde
{
	int		x;
	int		y;
	char	direction;
	int		w;
	int		s;
	int		d;
	int		a;
	int		right;
	int		left;
}	t_corde;

typedef struct s_global
{
	void		*mlx;
	void		*win;
	void		*window;
	void		**img;
	char		**map;
	char		**textures;
	char		**colors;
	char		**nums;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			empty_line;
	int			empty_line_2;
	int			width;
	int			height;
	t_corde		character;
	int			count_coll;
	int			count_exit;
	int			count_player;
	int			count_jumpline;
	int			lines_textures;
	int			lines_colors;
	int			lines_maps;
	int			max_length;
	char		**path_textures;
	char		**path_colors;
	char		**num2;
	int			rgb_f;
	int			rgb_c;
	int			color;
	int			k;
	int			t;
	char		**alb;	
}	t_global;

typedef struct s_pos
{
	double			pos_x;
	double			pos_y;
	double			ray_x;
	double			ray_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			camera_x;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				tex_width;
	int				tex_height;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	double			wall_x;
	double			step;
	double			tex_pos;
	void			*textura;
	unsigned int	*buffer;

}	t_pos;

typedef struct s_image
{
	void		*pointer;
	void		*image;
	int			x;
	int			y;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_text_norte
{
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	void			*tex_norte;
	int				tex_width;
	int				tex_height;
}	t_text_norte;

typedef struct s_text_sud
{
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	void			*tex_sud;
	int				tex_width;
	int				tex_height;
}	t_text_sud;

typedef struct t_text_oeste
{
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	void			*tex_oeste;
	int				tex_width;
	int				tex_height;
}	t_text_oeste;

typedef struct s_text_este
{
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	void			*tex_este;
	int				tex_width;
	int				tex_height;
}	t_text_este;

typedef struct s_all
{
	t_pos			pos;
	t_global		global;
	t_text_norte	text_norte;
	t_text_sud		text_sud;
	t_text_este		text_este;
	t_text_oeste	text_oeste;
	t_corde			corde;
	t_image			image;
}	t_all;

void	show_error_msg(int option, char *str);
int		validate_and_read_map(char *filename, t_all *all);
void	show_error_msg(int option, char *str);
char	**read_map(char *filename, t_global *global);
int		array_str_count(char **arr);
int		ft_validate_name(char *filename);
char	**arr_push(char **arr, char *str);
void	validate_letters_map(t_global *global);
void	read_line(char *map, t_global *global);
void	validate_rectangle_walls(t_global *global);
void	validate_all_leters(t_global *global);
int		get_total_img(t_global *global);
void	**create_img_arr(t_global *global);
void	show_map(t_global *global);
void	set_mlx_and_window(t_global *global);
int		mover(int keycode, t_all *all);
void	move_main_char(t_global *global);
int		can_move(t_global *global);
char	get_direction(int keycode);
int		ft_strcmp(const char *str1, const char *str2);
void	clean_img(t_all *all);
int		close_event(void);
void	*transform_img(void *mlx, char *image);
int		split_map(t_global *global);
int		ft_matrix_len(char **matrix);
int		malloc_maps(t_global *global);
void	validate_map(t_global *global);
void	validate_one_player(t_global *global);
void	validate_rows(t_global *global);
int		validate_textures(t_global *global, int i, char **arr);
int		access_textures(char *filename);
int		validate_colors(t_global *global, int i, char **arr);
void	free_matrix(char ***matrix);
void	set_mlx_windows_and_pistolon(t_all *all);
void	calc(t_all *all);
int		main_loop(t_all *all);
int		release(int keycode, t_all *all);
void	init_data(t_all *all);
int		key_move(t_all *all);
void	ft_texture(t_all *all);
void	ft_get_textures(t_all *all);
void	printing(t_all *all, int x, int y);
void	texturing(t_all *all);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
void	move_left_vision(t_all *all);
void	move_right_vision(t_all *all);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_directions(t_all *all);
void	mlx_init_data(t_all *all);
void	validate_all_different_wall(t_global *global);
void	validate_first_last_row(t_global *global);
char	**ft_split_spaces(char *str);
void	check_color(int i, t_global *global);
int		check_commas(char *arr);

#endif
