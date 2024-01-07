/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:39:46 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/08 00:12:05 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    p(t_mlx *data)
{
    int x = 0;
    int y = 0;
    
    while (data->jeu[x])
    {
        y = 0;
        while (data->jeu[x][y])
        {
            if (data->jeu[x][y] == 'P')
            {
                data->player_x = x;                
                data->player_y = y;
                return ;              
            }
            y++;
        }
        x++;
    }
    return ;
}

void C(t_mlx *data)
{
    int x = 0;
    int y = 0;
    
    while (data->jeu[x])
    {
        y = 0;
        while (data->jeu[x][y])
        {
            if (data->jeu[x][y] == 'C')
            {
                data->c++;          
            }
            y++;
        }
        x++;
    }
    return ;
}

void locate_e(t_mlx *data)
{
    int x = 0;
    int y; 
    
    while (data->jeu[x])
    {
        y = 0;
        while (data->jeu[x][y])
        {
            if (data->jeu[x][y] == 'E')
            {
                data->sorti_y = x;
                data->sorti_x = y;
                return ;          
            }
            y++;
        }
        x++;
    }
    return ;
}

void    remove_e(t_mlx *data)
{
    data->i = 0;
    while (data->jeu[data->i])
    {
        data->j = 0;
        while (data->jeu[data->i][data->j])
        {
            if (data->jeu[data->i][data->j] == 'E')
            {
                data->jeu[data->i][data->j] = '0';
                printf("%s\n", data->jeu[data->i]);
            }
            data->j++;
        }
        data->i++;
    }
}

void    recup_img(t_mlx *data)
{
    int i;
    int j;

    data->sprite.player = mlx_xpm_file_to_image(data->mlx_ptr, "img/player.xpm", &i, &j);
    data->sprite.sol = mlx_xpm_file_to_image(data->mlx_ptr, "img/sol.xpm", &i, &j);
    data->sprite.wall = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall.xpm", &i, &j);
    data->sprite.exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit.xpm", &i, &j);
    data->sprite.bonus = mlx_xpm_file_to_image(data->mlx_ptr, "img/bonus.xpm", &i, &j);
}