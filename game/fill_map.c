/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 03:46:55 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/14 08:43:24 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_map2(t_mlx *data)
{
	p(data);
	data->j = 0;
	if (data->c == 0)
		data->jeu[data->sorti_y][data->sorti_x] = 'E';
}

void	fill_map(t_mlx *data)
{
	data->i = 0;
	while (data->jeu[data->i])
	{
		fill_map2(data);
		while (data->jeu[data->i][data->j])
		{
			if (data->jeu[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.player, data->j * 32, data->i * 32);
			if (data->jeu[data->i][data->j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.sol, data->j * 32, data->i * 32);
			if (data->jeu[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.bonus, data->j * 32, data->i * 32);
			if (data->jeu[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.wall, data->j * 32, data->i * 32);
			if (data->jeu[data->i][data->j] == 'E' && data->c == 0)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.exit, data->j * 32, data->i * 32);
			data->j++;
		}
		data->i++;
	}
}
