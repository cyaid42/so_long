/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:16:45 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/22 21:41:19 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_size(char **c, t_mlx *data)
{
	data->lon = 0;
	while (c[data->lon])
	{
		data->lar = 0;
		while (c[data->lon][data->lar])
			data->lar++;
		data->lon++;
	}
}

int	key_hook(int keycode, t_mlx *data)
{
	if (keycode == UP || keycode == REALUP)
		move_up(data);
	if (keycode == DOWN || keycode == REALDOWN)
		move_down(data);
	if (keycode == LEFT || keycode == REALLEFT)
		move_left(data);
	if (keycode == RIGHT || keycode == REALRIGHT)
		move_right(data);
	if (keycode == Q || keycode == ESC)
		return (exit_click(data));
	return (0);
}

void	mlx_l(char **c)
{
	static t_mlx	data = {0};

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	data.jeu = c;
	window_size(data.jeu, &data);
	locate_e(&data);
	col(&data);
	if (data.c != 0)
	{
		remove_e(&data);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.lar * 32, data.lon * 32,
			"so_long");
	if (!data.win_ptr)
		exit(0);
	recup_img(&data);
	fill_map(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
}
