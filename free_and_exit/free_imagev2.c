/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_imagev2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:46:03 by cyaid             #+#    #+#             */
/*   Updated: 2024/02/15 02:11:35 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_bonus(t_mlx *data)
{
	if (data->sprite.player)
		mlx_destroy_image(data->mlx_ptr, data->sprite.player);
	if (data->sprite.sol)
		mlx_destroy_image(data->mlx_ptr, data->sprite.sol);
	if (data->sprite.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprite.exit);
	if (data->sprite.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprite.wall);
}

void	free_exit(t_mlx *data)
{
	if (data->sprite.bonus)
		mlx_destroy_image(data->mlx_ptr, data->sprite.bonus);
	if (data->sprite.sol)
		mlx_destroy_image(data->mlx_ptr, data->sprite.sol);
	if (data->sprite.player)
		mlx_destroy_image(data->mlx_ptr, data->sprite.player);
	if (data->sprite.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprite.wall);
}

void	free_player(t_mlx *data)
{
	if (data->sprite.bonus)
		mlx_destroy_image(data->mlx_ptr, data->sprite.bonus);
	if (data->sprite.sol)
		mlx_destroy_image(data->mlx_ptr, data->sprite.sol);
	if (data->sprite.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprite.exit);
	if (data->sprite.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprite.wall);
}

void	free_sol(t_mlx *data)
{
	if (data->sprite.bonus)
		mlx_destroy_image(data->mlx_ptr, data->sprite.bonus);
	if (data->sprite.player)
		mlx_destroy_image(data->mlx_ptr, data->sprite.player);
	if (data->sprite.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprite.exit);
	if (data->sprite.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprite.wall);
}

void	free_wall(t_mlx *data)
{
	if (data->sprite.bonus)
		mlx_destroy_image(data->mlx_ptr, data->sprite.bonus);
	if (data->sprite.sol)
		mlx_destroy_image(data->mlx_ptr, data->sprite.sol);
	if (data->sprite.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprite.exit);
	if (data->sprite.player)
		mlx_destroy_image(data->mlx_ptr, data->sprite.player);
}
