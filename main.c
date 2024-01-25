/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:22:07 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/25 10:30:50 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif(char **c, t_data *data)
{
	data->i = 0;
	if (premiere_ligne(c) == 1 && middle(c) == 1 && ligne_du_bas(c) == 1
		&& contenu_check(c) == 1 && ft_line_len(c) == 1
		&& vrai_rectangle(c) == 1)
	{
		finding_p(c, data);
		if (ft_pathfinding(data->copie, data) == 1)
		{
			data->i = 0;
			ft_printf("\n\n  |MAP_OVERWIEW|	\n\n");
			while (c[data->i])
				ft_printf("\n%s", c[data->i++]);
			ft_printf("\n");
			free_map(data->copie);
			free(data);
			mlx_l(c);
			return (1);
		}
	}
	ft_printf("Error\nMap is not complet\n");
	free_map(data->copie);
	vidange(data->map);
	free(data);
	return (-1);
}

int	check_file(char *file, t_data *data)
{
	if (!check_extension(file))
	{
		ft_printf("Error\nExtension non correcte\n");
		return (-1);
	}
	data->stock = NULL;
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
	{
		ft_printf("Error\nLe fichier n'existe pas");
		close(data->fd);
		return (-1);
	}
	return (1);
}

void	empty_line(t_data *data)
{
	if (data->ligne[0] == '\n')
	{
		while (1)
		{
			free(data->ligne);
			data->ligne = get_next_line(data->fd);
			if (!data->ligne)
				break ;
		}
		ft_printf("Error\nEmpty Line");
		free(data->stock);
		free(data->ligne);
		close(data->fd);
		free(data);
		exit(1);
	}
}

void	init_game(char *file, t_data *data)
{
	if (check_file(file, data) == -1)
		exit(1);
	data->ligne = get_next_line(data->fd);
	if (!data->ligne)
	{
		ft_printf("Error\nProbleme de");
		close(data->fd);
		free(data->ligne);
		return (free(data));
	}
	while (1)
	{
		empty_line(data);
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
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (!env)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
	{
		free(data);
		write(2, "Error\nMalloc failed\n", 21);
		return (0);
	}
	if (argc != 2)
	{
		free(data);
		ft_printf("Error'\nNombre d'argument non valable\n");
		return (0);
	}
	init_game(argv[1], data);
}
