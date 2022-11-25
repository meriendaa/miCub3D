/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:23:18 by albertmanta       #+#    #+#             */
/*   Updated: 2022/10/21 16:10:43 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	show_error_msg(int option, char *str)
{
	if (option == 1)
		printf("Error en las texturas");
	else if (option == 2)
		printf("Error en los coleres cielo y tierra");
	else if (option == 3)
		printf("Error en el mapa");
	else if (option == 4)
		printf("Error en abrir juego");
	else if (option == 5)
		printf("Error en el numero de jugadores");
	else if (option == 6)
		printf("Error en paredes: %s", str);
	exit(1);
}

void	mlx_init_data(t_all *all)
{
	all->global.mlx = mlx_init();
	all->global.win = mlx_new_window(all->global.mlx, WIDTH, HEIGHT, "cub3d");
	all->global.img = mlx_new_image(all->global.mlx, WIDTH, HEIGHT);
	all->global.addr = mlx_get_data_addr(all->global.img,
			&all->global.bits_per_pixel, &all->global.line_length,
			&all->global.endian);
}
