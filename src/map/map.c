/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 13:08:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/24 15:28:09 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>

BOOL	ftc_starts_with_any(char *src1, const char **lst)
{
	UINT	index;
	UINT	item;

	if (!src1)
		ft_exit_error_d("libft: ftc_starts_with_any: got a NULL cstring");
	item = 0;
	while (lst[item])
	{
		index = 0;
		while (lst[item][index] && src1[index] == lst[item][index])
			index++;
		if (!lst[item][index])
			return (TRUE);
		item++;
	}
	return (FALSE);
}

BOOL	is_path(char *line)
{
	const char	*extensions[] = {".xpm\n", ".png\n", NULL};
	size_t		len;

	len = ft_strlen(line);
	if (len < 4)
		return (FALSE);
	return (ftc_starts_with_any(line + (len - 5), extensions));
}

BOOL	is_color(char *line)
{
	unsigned long long	rgb[3];
	int					offset;
	int					i;
	int					index;

	offset = 0;
	i = 0;
	index = 0;
	rgb[0] = 256;
	rgb[1] = 256;
	rgb[2] = 256;
	while (line[i] && (i == 0 || line[i - 1] != '\n')
		&& ((ft_isdigit(line[i - 1]) && line[i] == ','
				&& ft_isdigit(line[i + 1])) || ft_isdigit(line[i])
			|| line[i] == '\n'))
	{
		if (index > 2)
			return (FALSE);
		if (line[i] == ',' || line[i] == '\n')
		{
			rgb[index] = ft_atou(line + offset);
			index++;
			offset = i + 1;
		}
		i++;
	}
	return (i <= 12 && rgb[0] < 256 && rgb[1] < 256 && rgb[2] < 256);
}

BOOL	is_info(t_ft_string *line)
{
	const char	*paths[] = {"NO ", "SO ", "WE ", "EA ", NULL};
	const char	*colors[] = {"F ", "C ", NULL};

	if (ftc_starts_with_any(line->text, paths))
		return (is_path(line->text + 3));
	if (ftc_starts_with_any(line->text, colors))
		return (is_color(line->text + 2));
	return (line->len == 1 && line->text[0] == '\n');
}

BOOL	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

t_ft_string	*get_prefixed_line(t_ft_list *info_lines, char *pref)
{
	t_ft_string	*cur;
	int			i;
	t_ft_string	*found;

	i = 0;
	found = NULL;
	while (i < info_lines->len)
	{
		cur = ft_list_item_at(info_lines, i);
		if (ft_strstr(cur, pref) == cur)
		{
			if (found)
				ft_exit_error("Duplicate info.");
			found = cur;
		}
		i++;
	}
	if (!found)
		ft_exit_error("Missing info.");
	return (found);
}

t_mlx_image	*get_image_from_path(t_data *data, t_ft_list *info_lines, char *pref)
{
	t_ft_string	*line;
	t_xpm		*xpm;
	t_mlx_tex	*tex;
	t_mlx_image	*img;

	line = get_prefixed_line(info_lines, pref);
	img = NULL;
	//if line ends with .xpm
		xpm = mlx_load_xpm42(line->text + ft_strlen(pref));
		img = mlx_texture_to_image(data->mlx, &xpm->texture);
		mlx_delete_xpm42(xpm);
	//else if line ends with .png
		tex = mlx_load_png(line->text + ft_strlen(pref));
		img = mlx_texture_to_image(data->mlx, tex);
		mlx_delete_texture(tex);
	return (img);
}

COLOR	*get_color(t_ft_list *info_lines, char *pref)
{
	unsigned long long	rgb[3];
	t_ft_string			*line;
	int					offset;
	int					i;
	int					index;

	line = get_prefixed_line(info_lines, pref);
	offset = 0;
	i = 0;
	index = 0;
	rgb[0] = 256;
	rgb[1] = 256;
	rgb[2] = 256;
	while (line->text[i] && (i == 0 || line->text[i - 1] != '\n')
		&& ((ft_isdigit(line->text[i - 1]) && line->text[i] == ','
				&& ft_isdigit(line->text[i + 1])) || ft_isdigit(line->text[i])))
	{
		if (index > 2)
			return (FALSE);
		if (line->text[i] == ',' || line->text[i] == '\n')
		{
			rgb[index] = ft_atou(line + offset);
			index++;
			offset = i + 1;
		}
		i++;
	}
	return (i <= 12 && rgb[0] < 256 && rgb[1] < 256 && rgb[2] < 256);
}

void	insert_color_data(unsigned int *data, t_ft_list *info_lines, char *pref)
{
	t_ft_string	*cur;
	int			i;
	BOOL		found;

	i = 0;
	found = FALSE;
	while (i < info_lines->len)
	{
		cur = ft_list_item_at(info_lines, i);
		if (ft_strstr(cur, pref) == cur)
		{
			if (found)
				ft_exit_error("Duplicate info.");
			found = TRUE;
			*data = ml_rgb(0, 0, 0);
		}
		i++;
	}
	if (!found)
		ft_exit_error("Missing info.");
}

void	load_info(t_data *data, t_ft_string **line)
{
	int			i;
	t_ft_list	*info_lines;

	i = 0;
	info_lines = ft_list_new();
	while (i < data->map->len)
	{
		*line = ft_list_item_at(data->map, i);
		if (is_info(*line) == FALSE)
			break ;
		if ((*line)->len > 1)
			ft_list_add_back(info_lines, *line);
	}
	insert_data(data, info_lines, "NO ");
	insert_data(data, info_lines, "SO ");
	insert_data(data, info_lines, "WE ");
	insert_data(data, info_lines, "EA ");
	insert_data(data, info_lines, "F ");
	insert_data(data, info_lines, "C ");
	ft_list_free(info_lines);
}

t_ft_list	*remove_newlines(t_ft_list	*map)
{
	t_ft_string	*line;
	int	i;

	i = 0;
	while (i < map->len)
	{
		line = ft_list_item_at(map, i);
		if (line->text[line->len - 1] != '\n')
			continue ;
		ft_string_free(ft_string_cutout(line, line->len - 1, 1));
	}
	return (map);
}

void	import_map_from_file(t_data *data, char *file_name)
{
	t_ft_string	*line;
	BOOL		map_mode;
	int			i;
	int			j;

	data->map = remove_newlines(ft_file_to_list(file_name));
	map_mode = FALSE;
	i = 0;
	load_info(data, &line);
	while (i < data->map->len)
	{
		line = ft_list_item_at(data->map, i);
		if (map_mode == FALSE && is_info(line) == FALSE)
			map_mode = TRUE;
		if (!map_mode)
			printf("INFO LINE\n");
		else
		{
			j = 0;
			while (line->text[j] && line->text[j] != '\n')
				if (is_map_char(line->text[j++]) == FALSE)
					ft_exit_error("Incorrect character in map.");
		}
		i++;
	}
}

char	true_map_get_at(t_ft_list *map, UINT x, UINT y)
{
	t_ft_string	*line;

	if (y >= (UINT)map->len)
		return ('\0');
	line = ft_list_item_at(map, y);
	if (x >= line->len)
		return ('\0');
	return (line->text[x]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	printf("a\n");
	import_map_from_file(&data, argv[1]);
	printf("b\n");
	if (argc != 2)
		return (2);
}
