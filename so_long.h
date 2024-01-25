/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:46 by cyaid             #+#    #+#             */
/*   Updated: 2024/01/25 02:59:43 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "utils/Printf/ft_printf.h"
# include "utils/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <sys/stat.h>

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define REALUP 65362
# define REALDOWN 65364
# define REALLEFT 65361
# define REALRIGHT 65363
# define Q 113
# define ESC 65307

typedef struct s_data
{
	int			i;
	int			j;
	int			tmpi;
	int			tmpj;
	int			k;
	int			l;
	int			fd;
	char		*stock;
	char		**map;
	int			relance;
	char		**copie;
	char		*ligne;

}				t_data;

typedef struct s_sprite
{
	void		*player;
	void		*exit;
	void		*bonus;
	void		*sol;
	void		*wall;
}				t_sprite;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		data;
	t_sprite	sprite;
	int			i;
	int			j;
	int			player_x;
	int			player_y;
	int			sorti_x;
	int			sorti_y;
	char		**jeu;
	int			c;
	int			movenmbr;
	int			lon;
	int			lar;
}				t_mlx;

// Deplacement//
int				haut(char **c, t_data *data);
int				bas(char **c, t_data *data);
int				gauche(char **c, t_data *data);
int				droite(char **c, t_data *data);
int				haut2(char **c, t_data *data);
int				bas2(char **c, t_data *data);
int				gauche2(char **c, t_data *data);
int				droite2(char **c, t_data *data);

// Contenu-Verif//
int				verif(char **c, t_data *data);
int				premiere_ligne(char **c);
int				middle(char **c);
int				ligne_du_bas(char **c);
int				contenu_check(char **c);
int				ft_line_len(char **c);
int				ft_contenu(char **c);
int				ft_contenu2(char **c);
int				vrai_rectangle(char **c);

// Map faisable//
int				ft_pathfinding(char **c, t_data *data);
int				map(char **c, t_data *data);
int				map2(char **c, t_data *data);
int				pc_or_e(char **c);
void			run(char **c, t_data *data);
void			finding_p(char **c, t_data *data);

// Util//
char			**ft_split(char const *s, char c);

// MLX//
void			mlx_l(char **c);
void			player(char **c, t_mlx *data);
void			sol(char **c, t_mlx *data);
void			mur(char **c, t_mlx *data);
void			collectible(char **c, t_mlx *data);
void			sorti(char **c, t_mlx *data);
void			new_sorti(char **c, t_mlx *data);
void			p(t_mlx *data);
void			new_sol(char **c, t_mlx *data);
void			fill_map(t_mlx *data);
void			col(t_mlx *data);
void			put_e(t_mlx *data);

// MLX MOVE//
int				move_up(t_mlx *data);
int				move_down(t_mlx *data);
int				move_left(t_mlx *data);
int				move_right(t_mlx *data);
void			move_up_util2(t_mlx *data);
void			move_down_util2(t_mlx *data);
void			move_left_util2(t_mlx *data);
void			move_right_util2(t_mlx *data);
void			move_down_util(t_mlx *data);
void			move_up_util(t_mlx *data);
void			move_right_util(t_mlx *data);
void			move_left_util(t_mlx *data);

// MLX FREE//
void			free_bonus(t_mlx *data);
void			free_exit(t_mlx *data);
void			free_player(t_mlx *data);
void			free_sol(t_mlx *data);
void			free_wall(t_mlx *data);

void			locate_e(t_mlx *data);
int				exit_click(t_mlx *data);
void			recup_img(t_mlx *data);
void			remove_e(t_mlx *data);
int				key_hook(int keycode, t_mlx *data);
int				check_extension(char *file);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			vidange(char **map);
void			free_map(char **map);
int				close_window(void *param);
void			free_imagev2(t_mlx *data);

#endif
