/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_les_contours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msan <msan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:10:40 by msan              #+#    #+#             */
/*   Updated: 2023/12/23 06:53:52 by msan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	premiere_ligne(char **c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (c[0][j] != '\0')
	{
		if (c[0][j] != '1')
		{
			printf("Error\nLigne du haut\n");
			return (-1);
		}
		j++;
	}
	return (1);
}

int	middle(char **c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (c[i + 1])
	{
		if (c[i][0] != '1')
		{
			printf("Error\nMilieu Gauche\n");
			return (-1);
		}
		if (c[i][ft_strlen(c[j]) - 1] != '1')
		{
			printf("Error\nMilieu Droite\n");
			return (-1);
		}
		i++;
		j++;
	}
	return (1);
}

int	ligne_du_bas(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i])
		i++;
	i--;
	while (c[i][j] != '\0')
	{
		if (c[i][j] != '1')
		{
			printf("Error\nLigne du bas\n");
			return (-1);
		}
		j++;
	}
	return (1);
}

int	vrai_rectangle(char **c)
{
	int	i;
	int	j;
	int	longueur;
	int	largeur;

	i = 0;
	j = 0;
	longueur = 0;
	largeur = 0;
	while (c[i][j])
	{
		while (c[i][j] != '\0')
		{
			j++;
			longueur++;
		}
	}
	while (c[i])
	{
		largeur++;
		i++;
	}
	if (longueur <= largeur)
		return (-1);
	return (1);
}
