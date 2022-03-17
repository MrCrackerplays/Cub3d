/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 16:22:08 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/17 16:58:47 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_try_to_load(t_data *data, t_mlx_image **img, char *file_path)
{
	t_mlx_texture	*png_tex;
	t_xpm			*xmp;

	if (*img)
		ft_exit_error("Reassigning of image.");
	test_access(file_path, "Can't load image.");
	if (ft_strcmp(file_path + ft_strlen(file_path) - 4, ".png") == 0)
	{
		png_tex = mlx_load_png(file_path);
		*img = mlx_texture_to_image(data->mlx, png_tex);
		mlx_delete_texture(png_tex);
	}
	else if (ft_strcmp(file_path + ft_strlen(file_path) - 4, ".xmp") == 0)
	{
		printf("trying to load xmp {%s}\n", file_path);
		xmp = mlx_load_xpm42(file_path);
		*img = mlx_texture_to_image(data->mlx, &(xmp->texture));
		mlx_delete_xpm42(xmp);
	}
	else
		ft_exit_error("Wrong image file type.");
}

static BYTE	static_get_color(char *src)
{
	UINT	len;

	len = 0;
	while (src[len] != '\0' && src[len] != ',')
	{
		if (!ft_isdigit(src[len]))
			ft_exit_error("Wrong color format.");
		len++;
	}
	if (ft_atou(src) > 255)
		ft_exit_error("Wrong color format.");
	return (ft_atou(src));
}

static void
	static_try_load_color(COLOR *c, t_ft_string *line, bool *b)
{
	int	i;

	if (*b)
		ft_exit_error("Reassigning of color.");
	*b = true;
	if (line->len < 7)
		ft_exit_error("Wrong color format.");
	i = 1;
	while (line->text[i] == ' ')
		i++;
	*c = 255;
	*c |= (static_get_color(line->text + i) << 24);
	while (line->text[i] != ',')
		i++;
	i++;
	*c |= static_get_color(line->text + i) << 16;
	while (line->text[i] != ',')
		i++;
	i++;
	*c |= static_get_color(line->text + i) << 8;
}

static void	static_parse_thing(
	t_data *data, t_ft_hash_map *texs, bool *r, bool *f)
{
	t_ft_string	*line;
	char		*des;

	while (true)
	{
		line = ft_list_pop_front(data->map);
		des = ft_strndup(line->text, 3);
		if (line->len == 0)
			;
		else if (ft_hash_map_has_key(texs, des))
			static_try_to_load(
				data, ft_hash_map_get(texs, des), skip_space(line->text + 2));
		else if (ft_strncmp(line->text, "F ", 2) == 0)
			static_try_load_color(&data->floor, line, f);
		else if (ft_strncmp(line->text, "C ", 2) == 0)
			static_try_load_color(&data->roof, line, r);
		else
			break ;
		ft_free3(des, line->text, line);
	}
	ft_list_add_front(data->map, line);
	free(des);
}

void	format_map(t_data *data, bool r, bool f)
{
	t_ft_hash_map	*texs;

	texs = ft_hash_map_new(100);
	ft_hash_map_set(texs, "NO ", &data->north);
	ft_hash_map_set(texs, "SO ", &data->south);
	ft_hash_map_set(texs, "EA ", &data->east);
	ft_hash_map_set(texs, "WE ", &data->west);
	ft_hash_map_set(texs, "D0 ", &data->door[0]);
	ft_hash_map_set(texs, "D1 ", &data->door[1]);
	ft_hash_map_set(texs, "D2 ", &data->door[2]);
	ft_hash_map_set(texs, "S0 ", &data->sprite[0]);
	ft_hash_map_set(texs, "S1 ", &data->sprite[1]);
	ft_hash_map_set(texs, "S2 ", &data->sprite[2]);
	ft_hash_map_set(texs, "CI ", &data->ceil_img);
	ft_hash_map_set(texs, "FI ", &data->floor_img);
	static_parse_thing(data, texs, &r, &f);
	ft_hash_map_free(texs);
	if (!r || !f || !data->north || !data->south || !data->west || !data->east
		|| !data->door[0] || !data->door[1] || !data->door[2]
		|| !data->sprite[0] || !data->sprite[1] || !data->sprite[2]
		|| !data->ceil_img || !data->floor_img)
		ft_exit_error("Invalid map.");
}
