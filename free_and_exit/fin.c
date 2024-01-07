/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:01:46 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/07 23:38:45 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_img(t_mlx *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprite.player);
	mlx_destroy_image(data->mlx_ptr, data->sprite.exit);
	mlx_destroy_image(data->mlx_ptr, data->sprite.bonus);
	mlx_destroy_image(data->mlx_ptr, data->sprite.sol);
	mlx_destroy_image(data->mlx_ptr, data->sprite.wall);
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
	//free(data);
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
	// free(data);
	exit(1);
	return (0);
}

