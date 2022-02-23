/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:54:34 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/23 14:31:47 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <libft.h>
# undef __USE_MISC
# define __USE_MISC
# include <math.h>

# define COLOR unsigned int

# define MOVE_SPEED .05
# define ROT_SPEED .05
# define WIDTH 1280
# define HEIGHT 720

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
	float	len;
	char	wall_face;
	float	pos_on_wall;
	char	wall_type;
}	t_ray;

typedef struct s_sprite
{
	t_mlx_image	*image;
	t_fv		pos;
}	t_sprite;

typedef struct s_data {
	t_mlx		*mlx;
	t_mlx_image	*screen;
	t_ft_list	*map;
	t_fv		player_pos;
	float		player_angle;
	float		fov;
	int			ray_skip;
	int			ray_depth;
	t_ray		rays[WIDTH + 1];
	COLOR		roof;
	COLOR		floor;
	t_mlx_image	*minimap;
	float		map_s;
	t_fv		map_pos;
}	t_data;

COLOR	ml_rgba(BYTE r, BYTE g, BYTE b, BYTE a);
COLOR	ml_rgb(BYTE r, BYTE g, BYTE b);
BYTE	ml_color_r(COLOR rgba);
BYTE	ml_color_g(COLOR rgba);
BYTE	ml_color_b(COLOR rgba);
BYTE	ml_color_a(COLOR rgba);

void	ml_draw_pixel(t_mlx_image *img, int x, int y, COLOR color);
void	ml_draw_box(t_mlx_image *image, t_iv pos, t_iv size, COLOR color);
void	ml_draw_line(t_mlx_image *image, t_iv p1, t_iv p2, COLOR color);

float	find_angle(t_fv p1, t_fv p2);

void	init_game(t_data *data);

void	player_movement_hook(void *param);
void	ray_cast_hook(void *param);

void	minimap_hook(void *param);

char	map_get_at(t_ft_list *map, UINT x, UINT y);

bool	is_wall(char c);

#endif
