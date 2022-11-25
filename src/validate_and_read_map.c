/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_read_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/10/05 20:33:41 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	validate_and_read_map(char *filename, t_all *all)
{
	ft_validate_name(filename);
	read_map(filename, &all->global);
	if (!all->global.map[0])
	{
		free_matrix(&all->global.map);
		return (1);
	}
	return (0);
}

char	**read_map(char *filename, t_global *global)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		show_error_msg(1, "Error\n La ruta del mapa no es correcta");
	global->map = ft_calloc(sizeof(char *), 1);
	if (global->map == NULL)
		show_error_msg(1, "Error\n de memoria.\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			global->map = arr_push(global->map, line);
		else
			break ;
	}
	close(fd);
	return (global->map);
}

int	ft_validate_name(char *filename)
{
	if (!ft_strnstr(filename, ".cub", ft_strlen(filename)))
		show_error_msg(3, "Error extension mapa");
	return (0);
}

int	array_str_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

char	**arr_push(char **arr, char *str)
{
	int		i;
	int		n;
	char	**new;

	i = 0;
	n = array_str_count(arr);
	new = ft_calloc(sizeof(char *), n + 2);
	while (i < n)
	{
		new[i] = arr[i];
		i++;
	}
	new[i] = str;
	free(arr);
	return (new);
}
