/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:54:34 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/29 14:00:24 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include <libft.h>
# include <stdbool.h>
# undef __USE_MISC
# define __USE_MISC
# include <math.h>

# include "cub_macros.h"

typedef struct s_fvector {
	float	x;
	float	y;
}	t_fv;

typedef struct s_ivector {
	int	x;
	int	y;
}	t_iv;

typedef struct s_ray {
	t_fv	hit_pos;
	t_iv	hit_wall_pos;
	float	len;
	float	eye_len;
	char	wall_face;
	float	pos_on_wall;
	char	wall_type;
}	t_ray;

typedef struct s_data {
	t_mlx		*mlx;
	t_mlx_image	*screen;
	t_ft_list	*map;
	t_fv		player_pos;
	float		player_angle;
	float		fov;
	int			ray_depth;
	t_ray		rays[WIDTH + 1];
	COLOR		roof;
	COLOR		floor;
	t_mlx_image	*north;
	t_mlx_image	*east;
	t_mlx_image	*south;
	t_mlx_image	*west;
}	t_data;

COLOR			ml_color_darken(COLOR c, float darkness_mod);

COLOR			ml_color_at(t_mlx_image *img, UINT x, UINT y);
void			ml_draw_pixel(t_mlx_image *img, UINT x, UINT y, COLOR color);

float			find_angle(t_fv p1, t_fv p2);
char			*skip_space(char *src);
void			test_access(char *file_path, char *message);
float			ray_angle_fix(t_data *data, int i);

void			init_game(t_data *data);

void			import_map(char *path, t_data *data);
void			format_map(t_data *data);
void			validate_map(t_data *data);

void			player_movement_hook(void *param);
void			ray_cast_hook(void *param);

void			map_hook(t_data *data);

char			map_get_at(t_ft_list *map, UINT x, UINT y);

char			is_wall(char c);

t_ft_hash_map	*format_init(t_data *data);
void			format_check(t_data *data, bool r, bool f);

bool			is_in_wall_and_set_player(t_data *data, t_iv pos, char c);

#endif
