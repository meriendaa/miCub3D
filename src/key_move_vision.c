/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_vision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:57:57 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 19:57:59 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_right_vision(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->pos.dir_x;
	all->pos.dir_x = all->pos.dir_x * cos(-all->pos.rot_speed)
		- all->pos.dir_y * sin(-all->pos.rot_speed);
	all->pos.dir_y = old_dir_x * sin(-all->pos.rot_speed)
		+ all->pos.dir_y * cos(-all->pos.rot_speed);
	old_plane_x = all->pos.plane_x;
	all->pos.plane_x = all->pos.plane_x * cos(-all->pos.rot_speed)
		- all->pos.plane_y * sin(-all->pos.rot_speed);
	all->pos.plane_y = old_plane_x * sin(-all->pos.rot_speed)
		+ all->pos.plane_y * cos(-all->pos.rot_speed);
}

void	move_left_vision(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->pos.dir_x;
	all->pos.dir_x = all->pos.dir_x * cos(all->pos.rot_speed)
		- all->pos.dir_y * sin(all->pos.rot_speed);
	all->pos.dir_y = old_dir_x * sin(all->pos.rot_speed)
		+ all->pos.dir_y * cos(all->pos.rot_speed);
	old_plane_x = all->pos.plane_x;
	all->pos.plane_x = all->pos.plane_x * cos(all->pos.rot_speed)
		- all->pos.plane_y * sin(all->pos.rot_speed);
	all->pos.plane_y = old_plane_x * sin(all->pos.rot_speed)
		+ all->pos.plane_y * cos(all->pos.rot_speed);
}
