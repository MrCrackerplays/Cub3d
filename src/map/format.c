/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 16:22:08 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/02 09:40:19 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_test_access(char *file_path)
{
	const int	fd = open(file_path, O_RDONLY);

	close(fd);
	if (fd < 0)
		ft_exit_error("Can't load image.");
}

static void	static_try_to_load(t_data *data, t_mlx_image **img, char *file_path)
{
	t_mlx_texture	*png_tex;
	t_xpm			*xmp;

	if (*img)
		ft_exit_error("Reassigning of image.");
	static_test_access(file_path);
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
	int		i;

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

void	format_map(t_data *data, bool r, bool f, t_ft_string *line)
{
	while (true)
	{
		line = ft_list_pop_front(data->map);
		if (line->len == 0)
			;
		else if (ft_strncmp(line->text, "NO ", 3) == 0)
			static_try_to_load(data, &data->north, skip_space(line->text + 2));
		else if (ft_strncmp(line->text, "SO ", 3) == 0)
			static_try_to_load(data, &data->south, skip_space(line->text + 2));
		else if (ft_strncmp(line->text, "EA ", 3) == 0)
			static_try_to_load(data, &data->east, skip_space(line->text + 2));
		else if (ft_strncmp(line->text, "WE ", 3) == 0)
			static_try_to_load(data, &data->west, skip_space(line->text + 2));
		else if (ft_strncmp(line->text, "F ", 2) == 0)
			static_try_load_color(&data->floor, line, &f);
		else if (ft_strncmp(line->text, "C ", 2) == 0)
			static_try_load_color(&data->roof, line, &r);
		else
			break ;
		ft_string_free(line);
	}
	ft_list_add_front(data->map, line);
	if (!r || !f || !data->north || !data->south || !data->west || !data->east)
		ft_exit_error("Invalid map (missing arguments).");
}
