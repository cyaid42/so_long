/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:12:50 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/18 08:22:55 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up_util2(t_mlx *data)
{
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_x--;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
	ft_printf("\n!!! Bravo, vous avez battu so_long !!!\n\n");
	exit_click(data);
}

void	move_down_util2(t_mlx *data)
{
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_x++;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
	ft_printf("\n!!! Bravo, vous avez battu so_long !!!\n\n");
	exit_click(data);
}

void	move_left_util2(t_mlx *data)
{
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_y--;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
	ft_printf("\n!!! Bravo, vous avez battu so_long !!!\n\n");
	exit_click(data);
}

void	move_right_util2(t_mlx *data)
{
	data->jeu[data->player_x][data->player_y] = '0';
	data->player_y++;
	data->jeu[data->player_x][data->player_y] = 'P';
	fill_map(data);
	ft_printf("\n!!! Bravo, vous avez battu so_long !!!\n\n");
	exit_click(data);
}
