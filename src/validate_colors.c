/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:24:41 by amantara          #+#    #+#             */
/*   Updated: 2022/11/25 12:11:26 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

int	save_num(t_global *global, char *nums)
{
	char	**arr;
	char	**arr2;
	char	**arr3;

	(void)global;
	arr3 = ft_split(nums, '\n');
	arr = ft_split(arr3[0], ' ');
	if (!ft_strcmp(arr[0], "F"))
	{
		arr2 = ft_split(arr[1], ',');
		global->rgb_f = rgb(ft_atoi(arr2[0]),
				ft_atoi(arr2[1]), ft_atoi(arr2[2]));
		free_matrix(&arr2);
	}
	if (!ft_strcmp(arr[0], "C"))
	{
		arr2 = ft_split(arr[1], ',');
		global->rgb_c = rgb(ft_atoi(arr2[0]),
				ft_atoi(arr2[1]), ft_atoi(arr2[2]));
		free_matrix(&arr2);
	}
	free_matrix(&arr);
	free_matrix(&arr2);
	free_matrix(&arr3);
	return (0);
}

int	save_color(t_global *global)
{
	int		i;

	i = 0;
	while (global->colors[i])
	{
		save_num(global, global->colors[i]);
		i++;
	}
	return (0);
}

int	check_nums(char *line_nums, char **arr, int i)
{
	if (check_commas(line_nums))
		return (1);
	arr = ft_split(line_nums, ',');
	if (arr[3])
		return (1);
	while (arr[i])
	{
		if (ft_isdigit(arr[i][0]))
		{
			if (ft_atoi(arr[i]) > 255 || ft_atoi(arr[i]) < 0)
			{
				free_matrix(&arr);
				return (1);
			}
		}
		else
		{
			free_matrix(&arr);
			return (1);
		}
		i++;
	}
	free_matrix(&arr);
	return (0);
}

int	validate_colors(t_global *global, int i, char **arr)
{
	check_color(i, global);
	while (global->colors[i])
	{
		arr = ft_split(global->colors[i], ' ');
		if (!ft_strcmp(arr[0], "F") || !ft_strcmp(arr[0], "C"))
		{
			if (check_nums(arr[1], arr, 0))
			{
				free_matrix(&arr);
				show_error_msg(2, "Error colores");
				break ;
			}
		}
		else
		{
			free_matrix(&arr);
			show_error_msg(2, "Error colores");
			break ;
		}
		free_matrix(&arr);
		i++;
	}
	save_color(global);
	return (0);
}
