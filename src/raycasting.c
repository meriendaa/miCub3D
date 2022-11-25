/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:49:34 by amantara          #+#    #+#             */
/*   Updated: 2022/10/26 20:32:42 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(t_all *all, int x)
{
	all->pos.camera_x = 2 * x / (double)WIDTH - 1;
	all->pos.ray_x = all->pos.dir_x + all->pos.plane_x * all->pos.camera_x;
	all->pos.ray_y = all->pos.dir_y + all->pos.plane_y * all->pos.camera_x;
	all->pos.map_x = (int)all->pos.pos_x;
	all->pos.map_y = (int)all->pos.pos_y;
	all->pos.hit = 0;
	all->pos.delta_dist_x = fabs(1 / all->pos.ray_x);
	all->pos.delta_dist_y = fabs(1 / all->pos.ray_y);
}

void	dda(t_all *all)
{
	while (all->pos.hit == 0)
	{
		if (all->pos.side_dist_x < all->pos.side_dist_y)
		{
			all->pos.side_dist_x += all->pos.delta_dist_x;
			all->pos.map_x += all->pos.step_x;
			all->pos.side = 0;
		}
		else
		{
			all->pos.side_dist_y += all->pos.delta_dist_y;
			all->pos.map_y += all->pos.step_y;
			all->pos.side = 1;
		}
		if (all->global.nums[all->pos.map_x][all->pos.map_y] == '1')
			all->pos.hit = 1;
	}
}

void	get_next_step(t_all *all)
{
	if (all->pos.ray_x < 0)
	{
		all->pos.step_x = -1;
		all->pos.side_dist_x = (all->pos.pos_x
				- all->pos.map_x) * all->pos.delta_dist_x;
	}
	else
	{
		all->pos.step_x = 1;
		all->pos.side_dist_x = (all->pos.map_x + 1.0
				- all->pos.pos_x) * all->pos.delta_dist_x;
	}
	if (all->pos.ray_y < 0)
	{
		all->pos.step_y = -1;
		all->pos.side_dist_y = (all->pos.pos_y
				- all->pos.map_y) * all->pos.delta_dist_y;
	}
	else
	{
		all->pos.step_y = 1;
		all->pos.side_dist_y = (all->pos.map_y + 1.0
				- all->pos.pos_y) * all->pos.delta_dist_y;
	}
}

void	draw(t_all *all)
{
	if (all->pos.side == 0)
		all->pos.perp_wall_dist = (all->pos.map_x
				- all->pos.pos_x + (1 - all->pos.step_x) / 2)
			/ all->pos.ray_x;
	else
		all->pos.perp_wall_dist = (all->pos.map_y
				- all->pos.pos_y + (1 - all->pos.step_y) / 2)
			/ all->pos.ray_y;
	all->pos.line_h = (int)(HEIGHT / all->pos.perp_wall_dist);
	all->pos.draw_start = -all->pos.line_h / 2 + HEIGHT / 2;
	if (all->pos.draw_start < 0)
		all->pos.draw_start = 0;
	else
		all->pos.draw_start = all->pos.draw_start;
	all->pos.draw_end = all->pos.line_h / 2 + HEIGHT / 2;
	if (all->pos.draw_end >= HEIGHT)
		all->pos.draw_end = HEIGHT - 1;
	else
		all->pos.draw_end = all->pos.draw_end;
	all->pos.tex_num = (int)all->global.nums[all->pos.map_x][all->pos.map_y];
}

int	main_loop(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		init_ray(all, x);
		get_next_step(all);
		dda(all);
		draw(all);
		texturing(all);
		printing(all, x, y);
		x++;
	}
	mlx_put_image_to_window(all->global.mlx, all->global.win,
		all->global.img, 0, 0);
	key_move(all);
	return (1);
}
