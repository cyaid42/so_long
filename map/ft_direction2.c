/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 03:52:33 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/10 02:32:19 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	bas2(char **c, t_data *data)
{
	while (c[data->k + 1][data->l] != '1')
	{
		data->k++;
		c[data->k][data->l] = 'X';
	}
	data->l = 0;
	return (-1);
}

int	haut2(char **c, t_data *data)
{
	while (c[data->k - 1][data->l] != '1')
	{
		data->k--;
		c[data->k][data->l] = 'X';
	}
	data->l = 0;
	return (-1);
}

int	gauche2(char **c, t_data *data)
{
	while (c[data->k][data->l - 1] != '1')
	{
		data->l--;
		c[data->k][data->l] = 'X';
	}
	data->l = 0;
	return (-1);
}

int	droite2(char **c, t_data *data)
{
	while (c[data->k][data->l + 1] != '1')
	{
		data->l++;
		c[data->k][data->l] = 'X';
	}
	data->l = 0;
	return (-1);
}
