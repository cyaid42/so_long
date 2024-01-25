/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:15:37 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/25 03:05:16 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_down_util(t_mlx *data)
{
	data->movenmbr++;
	ft_printf("\nNombre de pas---->%d", data->movenmbr);
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_x++;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
}

void	move_left_util(t_mlx *data)
{
	data->movenmbr++;
	ft_printf("\nNombre de pas---->%d", data->movenmbr);
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_y--;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
}

void	move_up_util(t_mlx *data)
{
	data->movenmbr++;
	ft_printf("\nNombre de pas---->%d", data->movenmbr);
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_x--;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
}

void	move_right_util(t_mlx *data)
{
	data->movenmbr++;
	ft_printf("\nNombre de pas---->%d", data->movenmbr);
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_y++;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
}
