/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:39:55 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 20:24:17 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	texturing(t_all *all)
{
	if (all->pos.side == 0)
		all->pos.wall_x = all->pos.pos_y
			+ all->pos.perp_wall_dist * all->pos.ray_y;
	else
		all->pos.wall_x = all->pos.pos_x
			+ all->pos.perp_wall_dist * all->pos.ray_x;
	all->pos.wall_x -= floor((all->pos.wall_x));
	all->pos.tex_x = (int)(all->pos.wall_x * (double)all->pos.tex_width);
	if (all->pos.side == 0 && all->pos.ray_x > 0)
		all->pos.tex_x = all->pos.tex_width - all->pos.tex_x -1;
	if (all->pos.side == 1 && all->pos.ray_y < 0)
		all->pos.tex_x = all->pos.tex_width - all->pos.tex_x -1;
	all->pos.step = 1.0 * all->pos.tex_height / all->pos.line_h;
	all->pos.tex_pos = (all->pos.draw_start - HEIGHT / 2
			+ all->pos.line_h / 2) * all->pos.step;
}

void	printing(t_all *all, int x, int y)
{
	y = -1;
	while (y++ < all->pos.draw_start)
		my_mlx_pixel_put(all, x, y, (int)all->global.rgb_c);
	y = all->pos.draw_start;
	ft_get_textures(all);
	while (y < all->pos.draw_end)
	{
		all->pos.tex_y = (int)all->pos.tex_pos;
		all->pos.tex_pos += all->pos.step;
		all->global.color = all->pos.buffer[all->pos.tex_width
			* all->pos.tex_y + all->pos.tex_x];
		my_mlx_pixel_put(all, x, y, all->global.color);
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(all, x, y, (int)all->global.rgb_f);
		y++;
	}
}

void	put_pistolon(t_all *all)
{
	all->image.image = mlx_new_image(all->global.mlx,
			all->image.x, all->image.y);
	all->image.pointer = mlx_xpm_file_to_image(all->image.image,
			"assets/sprites/pistol.xpm", &all->image.x, &all->image.y);
	all->image.pixels = mlx_get_data_addr(all->image.image,
			&all->image.bits_per_pixel,
			&all->image.line_size, &all->image.endian);
	mlx_put_image_to_window(all->global.mlx,
		all->global.win, all->image.pointer, 825, 870);
}
