/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:22:07 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/08 00:24:18 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif(char **c, t_data *data)
{
	int	i;

	i = 0;
	if (premiere_ligne(c) == 1 && middle(c) == 1 && ligne_du_bas(c) == 1
		&& contenu_check(c, data) == 1 && ft_line_len(c) == 1
		&& vrai_rectangle(c) == 1)
	{
		finding_p(c, data);
		if (ft_pathfinding(data->copie, data) == 1)
		{
			i = 0;
			printf("\n\n  |MAP_OVERWIEW|	\n\n");
			while (c[i])
			{
				printf("\n%s", c[i]);
				i++;
			}
			printf("\n");
			mlx_l(c);
			return (1);
		}
	}
	printf("Error\nMap is not complet\n");
	return (-1);
}

int	check_file(char *file, t_data *data)
{
	if (!check_extension(file))
	{
		printf("Error\nExtension non correcte\n");
		return (-1);
	}
	data->stock = NULL;
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
	{
		printf("Error\nLe fichier n'existe pas");
		return (-1);
	}
}

int	init_game(char *file, t_data *data)
{
	if (check_file(file, data) == -1)
	{
		return (-1);
	}
	data->ligne = get_next_line(data->fd);
	while (1)
	{
		if (data->ligne[0] == '\n')
		{
			printf("Error\nEmpty Line");
			free(data->stock);
			return (-1);
		}
		data->stock = ft_strjoin(data->stock, data->ligne);
		free(data->ligne);
		data->ligne = get_next_line(data->fd);
		if (!data->ligne)
			break ;
	}
	close(data->fd);
	data->map = ft_split(data->stock, '\n');
	data->copie = ft_split(data->stock, '\n');
	free(data->stock);
	verif(data->map, data);
	vidange(data->map, data);
}

int	main(int	argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!&data)
	{
		printf("Error\nMalloc failed\n");
		return (0);
	}
	if (argc != 2)
	{
		free(data);
		printf("Error'\nNombre d'argument non valable\n");
		return (0);
	}
	init_game(argv[1], data);

}
