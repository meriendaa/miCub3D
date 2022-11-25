/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:08:35 by amantara          #+#    #+#             */
/*   Updated: 2022/10/28 16:31:41 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_directions_n(t_all *all)
{
	all->pos.pos_x = all->global.character.x + 0.05;
	all->pos.pos_y = all->global.character.y + 0.05;
	all->pos.dir_y = 0;
	all->pos.dir_x = -1;
	all->pos.plane_x = 0;
	all->pos.plane_y = 0.66;
}

void	ft_directions_s(t_all *all)
{
	all->pos.pos_x = all->global.character.x + 0.05;
	all->pos.pos_y = all->global.character.y + 0.05;
	all->pos.dir_y = 0;
	all->pos.dir_x = 1;
	all->pos.plane_x = 0;
	all->pos.plane_y = -0.66;
}

void	ft_directions_e(t_all *all)
{
	all->pos.pos_x = all->global.character.x + 0.05;
	all->pos.pos_y = all->global.character.y + 0.05;
	all->pos.dir_y = 1;
	all->pos.dir_x = 0;
	all->pos.plane_x = 0.66;
	all->pos.plane_y = 0;
}

void	ft_directions_w(t_all *all)
{
	all->pos.pos_x = all->global.character.x + 0.05;
	all->pos.pos_y = all->global.character.y + 0.05;
	all->pos.dir_y = -1;
	all->pos.dir_x = 0;
	all->pos.plane_x = -0.66;
	all->pos.plane_y = 0;
}

void	ft_directions(t_all *all)
{
	if (all->global.character.direction == 'N')
		ft_directions_n(all);
	if (all->global.character.direction == 'S')
		ft_directions_s(all);
	if (all->global.character.direction == 'W')
		ft_directions_w(all);
	if (all->global.character.direction == 'E')
		ft_directions_e(all);
}
