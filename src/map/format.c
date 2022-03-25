/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 16:22:08 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/25 12:51:54 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "map.h"

static void	static_try_to_load(t_data *data, t_mlx_image **img, char *file_path)
{
	t_mlx_texture	*png_tex;
	t_xpm			*xpm;

	if (*img)
		ft_exit_error("Reassigning of image.");
	test_access(file_path, "Can't load image.");
	if (ft_strcmp(file_path + ft_strlen(file_path) - 4, ".png") == 0)
	{
		png_tex = mlx_load_png(file_path);
		*img = mlx_texture_to_image(data->mlx, png_tex);
		mlx_delete_texture(png_tex);
	}
	else if (ft_strcmp(file_path + ft_strlen(file_path) - 6, ".xpm42") == 0)
	{
		xpm = mlx_load_xpm42(file_path);
		*img = mlx_texture_to_image(data->mlx, &(xpm->texture));
		mlx_delete_xpm42(xpm);
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

void	format_map(t_data *data)
{
	t_ft_hash_map	*texs;
	bool			f;
	bool			r;

	r = false;
	f = false;
	texs = format_init(data);
	static_parse_thing(data, texs, &r, &f);
	ft_hash_map_free(texs);
	format_check(data, r, f);
}
