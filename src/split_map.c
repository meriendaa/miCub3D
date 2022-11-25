/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:30:25 by amantara          #+#    #+#             */
/*   Updated: 2022/11/22 19:26:59 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	malloc_maps(t_global *global)
{
	global->textures = malloc(sizeof(char *) * (4 + 1));
	global->textures[4] = NULL;
	global->colors = malloc(sizeof(char *) * (2 + 1));
	global->colors[2] = NULL;
	global->nums = malloc(sizeof(char *)
			* (global->empty_line_2 - global->empty_line + 1));
	global->nums[global->empty_line_2 - global->empty_line] = NULL;
	global->path_textures
		= malloc(sizeof(char *) * (4 + 1));
	global->path_textures[4] = NULL;
	if (!global->textures || !global->colors || !global->nums)
	{
		show_error_msg(1, "Malloc error");
		return (0);
	}
	return (1);
}

void	fill_num(t_global *global, int i, int j)
{
	while (global->map[i])
	{
		global->nums[j] = ft_strdup(global->map[i]);
		i++;
		j++;
	}
}

void	fill_text(t_global *global, int i, int j)
{
	if (global->map[i][j] == 'N')
	{
			global->textures[global->t] = ft_strdup(global->map[i]);
			global->t++;
	}	
	if (global->map[i][j] == 'S')
	{
			global->textures[global->t] = ft_strdup(global->map[i]);
			global->t++;
	}
	if (global->map[i][j] == 'W')
	{
			global->textures[global->t] = ft_strdup(global->map[i]);
			global->t++;
	}	
	if (global->map[i][j] == 'E')
	{
			global->textures[global->t] = ft_strdup(global->map[i]);
			global->t++;
	}
}

void	fill_col(t_global *global, int i, int j)
{
	if (global->map[i][j] == 'F')
	{
		global->colors[global->k] = ft_strdup(global->map[i]);
		global->k++;
	}
	if (global->map[i][j] == 'C')
	{
		global->colors[global->k] = ft_strdup(global->map[i]);
		global->k++;
	}
}

int	split_map(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!malloc_maps(global))
		return (0);
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == ' ')
				j++;
			else
			{
				fill_col(global, i, j);
				fill_text(global, i, j);
				break ;
			}
		}
		i++;
	}
	fill_num(global, global->empty_line, 0);
	return (1);
}
