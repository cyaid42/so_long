/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:16:45 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/07 22:02:54 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    window_size(char **c, t_mlx *data)
{
    data->i = 0;
    while (c[data->i])
	{
		data->j = 0;
		while (c[data->i][data->j])
			data->j++;
		data->i++;
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
        return (mlx_loop_end(data->mlx_ptr));
    return (0);
}

void mlx_l(char **c)
{
    static t_mlx data = {0};
    data.jeu = c;
    window_size(c, &data);
    locate_e(&data);
    C(&data);
    if (data.c != 0)
    {
        remove_e(&data);        
    } 
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.j * 32, data.i * 32, "so_long");
    recup_img(&data);
    fill_map(data.jeu, &data);
    mlx_key_hook(data.win_ptr, key_hook, &data);
    mlx_loop(data.mlx_ptr);
}