/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:01:46 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/22 21:39:38 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_img(t_mlx *game)
{
	mlx_destroy_image(game->mlx_ptr, game->sprite.player);
	mlx_destroy_image(game->mlx_ptr, game->sprite.exit);
	mlx_destroy_image(game->mlx_ptr, game->sprite.bonus);
	mlx_destroy_image(game->mlx_ptr, game->sprite.sol);
	mlx_destroy_image(game->mlx_ptr, game->sprite.wall);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_win(t_mlx *data)
{
	free_img(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display((*data).mlx_ptr);
		free((*data).mlx_ptr);
	}
	free_map(data->jeu);
	free(data);
	exit(1);
}

int	exit_click(t_mlx *data)
{
	free_img(data);
	if (data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display((*data).mlx_ptr);
		free((*data).mlx_ptr);
	}
	free_map(data->jeu);
	exit(1);
	return (0);
}

int	close_window(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	exit_click(data);
	exit(0);
}
