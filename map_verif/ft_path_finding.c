/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:36:34 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/22 21:42:16 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	comptage(char **c, t_data *data)
{
	int	i;
	int	j;

	data->relance = 0;
	i = 0;
	j = 0;
	while (c[i])
	{
		while (c[i][j])
		{
			data->relance++;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_pathfinding(char **c, t_data *data)
{
	comptage(c, data);
	c[data->i][data->j] = 'X';
	if (map(c, data) == 1)
	{
		if (map2(c, data) == 1)
			return (1);
		else
		{
			ft_printf("Erro\nPathfinding not complet\n");
			return (-1);
		}
	}
	ft_printf("Erro\nPathfinding not complet\n");
	return (-1);
}
