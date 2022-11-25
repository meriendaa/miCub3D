/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateMap3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:50:24 by amantara          #+#    #+#             */
/*   Updated: 2022/11/16 18:45:35 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	copy_matrix_to_another_matrix(t_global *global, char **new_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j] && global->nums[i][j] != '\n')
		{
			new_matrix[i][j] = global->nums[i][j];
			j++;
		}
		i++;
	}
}

void	parser_map(t_global *global)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = malloc((ft_matrix_len(global->nums) + 1) * sizeof(char *));
	i = 0;
	while (global->nums[i])
	{
		new_map[i] = malloc(sizeof(char) * (global->max_length + 1));
		j = 0;
		while (j < global->max_length)
		{
			new_map[i][j] = ' ';
			j++;
		}
		new_map[i][j++] = '\n';
		new_map[i][j++] = '\0';
		i++;
	}
	new_map[i] = 0;
	copy_matrix_to_another_matrix(global, new_map);
	free_matrix(&global->nums);
	global->nums = new_map;
}

void	validate_letters(t_global *global)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j])
		{
			if (global->nums[i][j] != 'N' && global->nums[i][j] != 'S'
			&& global->nums[i][j] != 'E' && global->nums[i][j] != 'W'
			&& global->nums[i][j] != '1' && global->nums[i][j] != '0'
			&& global->nums[i][j] != '\t' && global->nums[i][j] != '\n'
			&& global->nums[i][j] != ' ')
			{
				show_error_msg(6, "caracter no valido.");
			}
			j++;
		}
		i++;
	}
}

void	validate_map(t_global *global)
{
	int	i;

	i = 0;
	global->count_player = 0;
	validate_letters(global);
	validate_one_player(global);
	parser_map(global);
	validate_first_last_row(global);
	validate_all_different_wall(global);
}
