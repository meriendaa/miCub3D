/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:25:55 by tmerida-          #+#    #+#             */
/*   Updated: 2022/11/25 12:10:33 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_spaces2(int i, int j, t_global *global)
{
	while (global->colors[i][j])
	{
		if (global->colors[i][j] == ' ')
			j++;
		if (global->colors[i][j] != ' ')
		{
			while (global->colors[i][j])
			{
				if (global->colors[i][j] == ' ')
					return (1);
				j++;
			}
		}
	}
	return (0);
}

int	check_spaces(int i, t_global *global)
{
	int	j;

	i = 0;
	if (global->k != 2)
	{
		return (1);
	}
	while (global->colors[i])
	{
		j = 0;
		while (global->colors[i][j])
		{
			if ((global->colors[i][j] == 'F' || global->colors[i][j] == 'C'))
			{
				j++;
				if (check_spaces2(i, j, global))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_color(int i, t_global *global)
{
	if (check_spaces(i, global))
	{
		show_error_msg(2, "Textura Vacia\n");
		mlx_clear_window(global->mlx, global->win);
		mlx_destroy_window(global->mlx, global->win);
		exit(0);
	}
}

int	check_commas(char *arr)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (arr[i])
	{
		if (arr[i] == ',')
			count++;
		if (count >= 4)
			return (1);
		i++;
	}
	return (0);
}
