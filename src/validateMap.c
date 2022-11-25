/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:50:37 by amantara          #+#    #+#             */
/*   Updated: 2022/10/28 16:40:11 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	upgrade_values(t_corde *cordeplayer, t_global *global, int j, int i)
{
	global->count_player++;
	cordeplayer->x = i;
	cordeplayer->y = j;
	cordeplayer->direction = global->nums[i][j];
}

void	validate_one_player(t_global *global)
{
	int		i;
	int		j;
	t_corde	cordeplayer;

	i = 0;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j])
		{
			if (global->nums[i][j] == 'N' || global->nums[i][j] == 'S'
				|| global->nums[i][j] == 'E' || global->nums[i][j] == 'W')
				upgrade_values(&cordeplayer, global, j, i);
			if (global->max_length < j)
				global->max_length = j;
			j++;
		}
		global->character = cordeplayer;
		i++;
	}
	if (global->count_player > 1 || global->count_player == 0)
		show_error_msg(5, "Error en el numero de jugadores");
}

void	validate_rows(t_global *global)
{
	int	i;
	int	j;

	i = 1;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j] == 32 && global->nums[i][j])
			j++;
		if (global->nums[i][j] != '1')
			show_error_msg(6, "Error en paredes");
		if (i < (ft_matrix_len(global->nums) - 1)
			&& global->nums[i][ft_strlen(global->nums[i]) - 2] != '1')
			show_error_msg(6, "Error en paredes");
		i++;
	}
}
