/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:54:34 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/12 20:05:19 by rdrazsky      ########   odam.nl         */
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
	t_iv	hit_wall_pos;
	float	len;
	float	eye_len;
	char	wall_face;
	float	pos_on_wall;
	char	wall_type;
}	t_ray;

typedef struct s_sprite
{
	t_mlx_image	*image;
	t_fv		pos;
	float		dis;
	float		eye_dis;
	float		size;
	float		size_x;
	float		size_y;
}	t_sprite;

typedef struct s_data {
	t_mlx		*mlx;
	t_mlx_image	*screen;
	t_ft_list	*map;
	t_fv		player_pos;
	float		player_angle;
	float		player_ud_angle;
	t_fv		dir;
	t_fv		plane;
	float		fov;
	int			ray_depth;
	t_ray		rays[WIDTH + 1];
	COLOR		roof;
	COLOR		floor;
	t_mlx_image	*north;
	t_mlx_image	*east;
	t_mlx_image	*south;
	t_mlx_image	*west;
	t_mlx_image	*door[3];
	t_mlx_image	*sprite[3];
	t_mlx_image	*minimap;
	float		map_s;
	t_fv		map_pos;
	double		game_time;
	t_ft_list	*sprites;
}	t_data;

COLOR		ml_rgba(BYTE r, BYTE g, BYTE b, BYTE a);
COLOR		ml_rgb(BYTE r, BYTE g, BYTE b);
BYTE		ml_color_r(COLOR rgba);
BYTE		ml_color_g(COLOR rgba);
BYTE		ml_color_b(COLOR rgba);
BYTE		ml_color_a(COLOR rgba);


COLOR		ml_color_at(t_mlx_image *img, UINT x, UINT y);
void		ml_draw_pixel(t_mlx_image *img, UINT x, UINT y, COLOR color);
void		ml_draw_box(t_mlx_image *image, t_iv pos, t_iv size, COLOR color);
void		ml_draw_line(t_mlx_image *image, t_iv p1, t_iv p2, COLOR color);

float		find_angle(t_fv p1, t_fv p2);
char		*skip_space(char *src);
void		test_access(char *file_path, char *message);
t_sprite	*sprite_new(float x, float y);
float		ray_angle_fix(t_data *data, int i);

void		init_game(t_data *data);

void		import_map(char *path, t_data *data);
void		format_map(t_data *data);
void		validate_map(t_data *data);

t_ray		cast_ray(t_data *data, float r_angle, t_fv pos, float mirror_len);

t_ray		mirror_hit(
				t_data *data, float r_angle, t_ray ray, float mirror_len);

void		player_movement_hook(void *param);
void		ray_cast_hook(void *param);

void		minimap_hook(t_data *data);
void		ceiling_hook(t_data *param);
void		map_hook(t_data *data);
void		sprite_hook(t_data *data);

char		map_get_at(t_ft_list *map, UINT x, UINT y);

char		is_wall(char c);

#endif
