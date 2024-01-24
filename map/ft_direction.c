/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msan <msan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:19:16 by cyaid             #+#    #+#             */
/*   Updated: 2023/12/23 05:32:50 by msan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	bas(char **c, t_data *data)
{
	while (c[data->i + 1][data->j] != '1')
	{
		data->i++;
		c[data->i][data->j] = 'X';
	}
	data->j = 0;
	return (-1);
}

int	haut(char **c, t_data *data)
{
	while (c[data->i - 1][data->j] != '1')
	{
		data->i--;
		c[data->i][data->j] = 'X';
	}
	return (-1);
}

int	gauche(char **c, t_data *data)
{
	while (c[data->i][data->j - 1] != '1')
	{
		data->j--;
		c[data->i][data->j] = 'X';
	}
	return (-1);
}

int	droite(char **c, t_data *data)
{
	while (c[data->i][data->j + 1] != '1')
	{
		data->j++;
		c[data->i][data->j] = 'X';
	}
	return (-1);
}
