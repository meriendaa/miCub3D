/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_letters_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:05:15 by albertmanta       #+#    #+#             */
/*   Updated: 2022/10/19 19:08:00 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	validate_rectangle_walls(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	if (global->height == global->width)
		show_error_msg(1, "Error\n El mapa tiene que ser rectangular.");
	while (i < global->height)
	{
		j = 0;
		while (global->map[i][j])
		{
			if (i == 0 || i == global->height - 1)
			{
				if (global->map[i][j] != '1' && global->map[i][j] != '\n')
					show_error_msg(1, "Error\n paredes ultima primera linea");
			}
			else if (j == 0 || j == global->width - 2)
			{
				if (global->map[i][j] != '1')
					show_error_msg(1, "Error\n paredes lineas del medio");
			}
			j++;
		}
		i++;
	}
}

void	read_line(char *map, t_global *global)
{
	int	i;

	(void) global;
	i = 0;
	while (map[i])
	{
	}
}

void	validate_all_leters(t_global *global)
{
	if (global->count_player > 1 || global->count_player == 0)
		show_error_msg(1, "Error\n de jugadores.");
}

void	validate_letters_map(t_global *global)
{
	int	i;

	global->count_player = 0;
	global->count_jumpline = 0;
	global->width = -1;
	i = 0;
	while (global->map[i])
	{
		read_line(global->map[i], global);
		i++;
	}
	global->height = i;
	validate_all_leters(global);
	validate_rectangle_walls(global);
}
