/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/10/28 16:31:08 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_file_lines(t_global *global, int i)
{
	while (global->map[i])
	{
		if (global->map[i][0] == '\n')
		{
			break ;
		}
		i++;
	}
	return (i);
}

int	count_empty_lines(t_global *global, int i, int count)
{
	if (global->map[i][0] == '\n')
	{
		while (global->map[i])
		{
			if (global->map[i][0] == '\n')
			{
				i++;
				count++;
			}
			else
				break ;
		}
	}
	return (count);
}

int	count_lines(t_global *global)
{
	int	i;

	i = 0;
	while (global->map[i])
	{
		if (global->map[i][0] == '1')
		{
			global->empty_line = i;
			break ;
		}
		i++;
	}
	i = global->empty_line;
	while (global->map[i])
	{
		i++;
	}
	global->empty_line_2 = i;
	global->t = 0;
	global->k = 0;
	return (1);
}

void	init_main(t_all *all, char **arr, int i)
{
	if (all->global.t != 4)
	{
		show_error_msg(1, "Textura Vacia\n");
		mlx_clear_window(all->global.mlx, all->global.win);
		mlx_destroy_window(all->global.mlx, all->global.win);
		exit(0);
	}
	validate_textures(&all->global, i, arr);
	validate_colors(&all->global, i, arr);
	validate_map(&all->global);
	init_data(all);
	ft_directions(all);
}

int	main(int argc, char **argv)
{
	t_all	all;
	int		i;
	char	**arr;

	arr = NULL;
	i = 0;
	if (argc == 2)
	{
		if (validate_and_read_map(argv[1], &all))
			show_error_msg(4, "FIchero vacio");
		if (!count_lines(&all.global))
			show_error_msg(1, "Error numero de texturas\n");
		if (!split_map(&all.global))
			return (0);
		init_main(&all, arr, i);
		mlx_init_data(&all);
		ft_texture(&all);
		mlx_hook(all.global.win, 02, (0L << 0), mover, &all);
		mlx_hook(all.global.win, 03, (0L << 0), release, &all);
		mlx_hook(all.global.win, 17, 0, close_event, &all);
		mlx_loop_hook(all.global.mlx, main_loop, &all);
		mlx_loop(all.global.mlx);
	}
	show_error_msg(1, "Error numero de parametro incorrecto");
	return (0);
}
