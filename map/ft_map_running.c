/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_running.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:19:24 by msan              #+#    #+#             */
/*   Updated: 2024/01/10 02:32:25 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	run(char **c, t_data *data)
{
	data->k = data->i;
	data->l = data->j;
	droite2(c, data);
	data->k = data->i;
	data->l = data->j;
	haut2(c, data);
	data->k = data->i;
	data->l = data->j;
	gauche2(c, data);
	data->k = data->i;
	data->l = data->j;
	bas2(c, data);
	data->k = data->i;
	data->l = data->j;
}

int	map(char **c, t_data *data)
{
	droite(c, data);
	data->i = data->tmpi;
	data->j = data->tmpj;
	haut(c, data);
	data->i = data->tmpi;
	data->j = data->tmpj;
	bas(c, data);
	data->i = data->tmpi;
	data->j = data->tmpj;
	gauche(c, data);
	data->i = data->tmpi;
	data->j = data->tmpj;
	return (1);
}

int	pc_or_e(char **c)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == 'P')
				a++;
			if (c[i][j] == 'E')
				a++;
			if (c[i][j] == 'C')
				a++;
			j++;
		}
		i++;
	}
	if (a != 0)
		return (-1);
	return (1);
}
