/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:00:24 by cyaid             #+#    #+#             */
/*   Updated: 2024/02/15 01:09:53 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_all(t_mlx *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data->jeu);
	free(data->mlx_ptr);
	exit (1);
}

void	free_imagev2(t_mlx *data)
{
	if (!data->sprite.wall && !data->sprite.sol && !data->sprite.player
		&& !data->sprite.exit && !data->sprite.bonus)
		free_all(data);
	else if (!data->sprite.bonus)
		free_bonus(data);
	else if (!data->sprite.exit)
		free_exit(data);
	else if (!data->sprite.player)
		free_player(data);
	else if (!data->sprite.sol)
		free_sol(data);
	else if (!data->sprite.wall)
		free_wall(data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data->jeu);
	free(data->mlx_ptr);
	exit(1);
}

void	vidange(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	i = 0;
}
