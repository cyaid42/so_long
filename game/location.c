/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:39:46 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/22 21:41:31 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	p(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->jeu[x])
	{
		y = 0;
		while (data->jeu[x][y])
		{
			if (data->jeu[x][y] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
	return ;
}

void	col(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->jeu[x])
	{
		y = 0;
		while (data->jeu[x][y])
		{
			if (data->jeu[x][y] == 'C')
			{
				data->c++;
			}
			y++;
		}
		x++;
	}
	return ;
}

void	locate_e(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->jeu[x])
	{
		y = 0;
		while (data->jeu[x][y])
		{
			if (data->jeu[x][y] == 'E')
			{
				data->sorti_y = x;
				data->sorti_x = y;
				return ;
			}
			y++;
		}
		x++;
	}
	return ;
}

void	remove_e(t_mlx *data)
{
	data->i = 0;
	while (data->jeu[data->i])
	{
		data->j = 0;
		while (data->jeu[data->i][data->j])
		{
			if (data->jeu[data->i][data->j] == 'E')
			{
				data->jeu[data->i][data->j] = '0';
			}
			data->j++;
		}
		data->i++;
	}
}

void	recup_img(t_mlx *data)
{
	int	w;

	data->sprite.bonus = mlx_xpm_file_to_image(data->mlx_ptr, "img/bonus.xpm",
			&w, &w);
	data->sprite.exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit.xpm", &w,
			&w);
	data->sprite.player = mlx_xpm_file_to_image(data->mlx_ptr, "img/player.xpm",
			&w, &w);
	data->sprite.sol = mlx_xpm_file_to_image(data->mlx_ptr, "img/sol.xpm", &w,
			&w);
	data->sprite.wall = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall.xpm", &w,
			&w);
	if ((!data->sprite.player || !data->sprite.bonus || !data->sprite.exit
			|| !data->sprite.sol || !data->sprite.wall))
		free_imagev2(data);
}
