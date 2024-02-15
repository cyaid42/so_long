/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:50:48 by cyaid             #+#    #+#             */
/*   Updated: 2024/02/15 00:44:09 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_up(t_mlx *data)
{
	if (data->jeu[data->player_x - 1][data->player_y] == '0')
		move_up_util(data);
	else if (data->jeu[data->player_x - 1][data->player_y] == 'C')
	{
		data->c--;
		move_up_util(data);
		if (data->c == 0)
		{
			ft_printf("\n\n<--------------------->");
			ft_printf("\n|CREATION DE LA SORTIE|");
			ft_printf("\n<--------------------->\n");
		}
	}
	else if (data->jeu[data->player_x - 1][data->player_y] == 'E'
		&& data->c == 0)
		move_up_util2(data);
	return (0);
}

int	move_down(t_mlx *data)
{
	if (data->jeu[data->player_x + 1][data->player_y] == '0')
		move_down_util(data);
	else if (data->jeu[data->player_x + 1][data->player_y] == 'C')
	{
		data->c--;
		move_down_util(data);
		if (data->c == 0)
		{
			ft_printf("\n\n<--------------------->");
			ft_printf("\n|CREATION DE LA SORTIE|");
			ft_printf("\n<--------------------->\n");
		}
	}
	else if (data->jeu[data->player_x + 1][data->player_y] == 'E'
		&& data->c == 0)
		move_down_util2(data);
	return (0);
}

int	move_left(t_mlx *data)
{
	if (data->jeu[data->player_x][data->player_y - 1] == '0')
		move_left_util(data);
	else if (data->jeu[data->player_x][data->player_y - 1] == 'C')
	{
		data->c--;
		move_left_util(data);
		if (data->c == 0)
		{
			ft_printf("\n\n<--------------------->");
			ft_printf("\n|CREATION DE LA SORTIE|");
			ft_printf("\n<--------------------->\n");
		}
	}
	else if (data->jeu[data->player_x][data->player_y - 1] == 'E'
		&& data->c == 0)
		move_left_util2(data);
	return (0);
}

int	move_right(t_mlx *data)
{
	if (data->jeu[data->player_x][data->player_y + 1] == '0')
		move_right_util(data);
	else if (data->jeu[data->player_x][data->player_y + 1] == 'C')
	{
		data->c--;
		move_right_util(data);
		if (data->c == 0)
		{
			ft_printf("\n\n<--------------------->");
			ft_printf("\n|CREATION DE LA SORTIE|");
			ft_printf("\n<--------------------->\n");
		}
	}
	else if (data->jeu[data->player_x][data->player_y + 1] == 'E'
		&& data->c == 0)
		move_right_util2(data);
	return (0);
}
