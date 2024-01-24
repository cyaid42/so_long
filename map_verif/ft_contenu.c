/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:18:30 by msan              #+#    #+#             */
/*   Updated: 2024/01/10 02:46:11 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finding_p(char **c, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i])
	{
		while (c[i][j])
		{
			if (c[i][j] == 'P')
			{
				data->i = i;
				data->j = j;
				data->tmpi = i;
				data->tmpj = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int	ft_contenu2(char **c)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	j = 0;
	collectible = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j] != '\0')
		{
			if (c[i][j] == 'C')
				collectible = collectible + 1;
			j++;
		}
		i++;
	}
	if (collectible < 1)
		return (-1);
	return (1);
}

int	ft_contenu(char **c)
{
	int	i;
	int	j;
	int	e;
	int	p;

	i = 0;
	e = 0;
	p = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j] != '\0')
		{
			if (c[i][j] == 'E')
				e = e + 1;
			if (c[i][j] == 'P')
				p = p + 1;
			j++;
		}
		i++;
	}
	if (e != 1 || p != 1 || ft_contenu2(c) == -1)
		return (-1);
	return (1);
}

int	contenu_check(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i] != NULL)
	{
		j = 0;
		while (c[i][j] != '\0')
		{
			if (c[i][j] != '0' && c[i][j] != '1' && c[i][j] != 'C'
				&& c[i][j] != 'E' && c[i][j] != 'P')
				return (-1);
			if (ft_contenu(c) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_line_len(char **c)
{
	int	i;
	int	j;
	int	count;
	int	count2;

	i = 0;
	j = 0;
	count = 0;
	count2 = 0;
	while (c[i])
	{
		count2 = 0;
		while (c[i] && c[i][j] != '\0')
		{
			j++;
			count2++;
		}
		if (i > 0 && count != count2)
			return (-1);
		count = count2;
		i++;
		j = 0;
	}
	return (1);
}
