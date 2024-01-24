/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 04:10:55 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/22 21:42:09 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map2(char **c, t_data *data)
{
	data->i = 1;
	data->j = 0;
	while (c[data->i])
	{
		while (c[data->i][data->j + 1])
		{
			if (c[data->i][data->j] == 'X')
				run(c, data);
			data->j++;
		}
		data->i++;
		data->j = 0;
	}
	if (data->relance >= 1)
	{
		data->relance--;
		map2(c, data);
	}
	if (pc_or_e(c) == 1)
		return (1);
	return (-1);
}
