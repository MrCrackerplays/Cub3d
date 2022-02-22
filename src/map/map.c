/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 13:08:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 15:08:59 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>
#include <libft.h>

BOOL	ftc_is_alpha(unsigned char c)//TODO: replace with libft alternative
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

BOOL	ftc_is_num(unsigned char c)//TODO: replace with libft alternative
{
	return (c >= '0' && c <= '9');
}

BOOL	ftc_is_alnum(unsigned char c)//TODO: replace with libft alternative
{
	return (ftc_is_alpha(c) || ftc_is_num(c));
}

BOOL	ftc_starts_with_any(char *src1, char **lst)
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
	const char	**extensions = {".xpm", ".png", NULL};
	size_t		len;

	len = ft_strlen(line);
	if (len < 4)
		return (FALSE);
	return (ftc_starts_with_any(line + (len - 4), extensions));
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
	while (line[i] && ((ftc_is_num(line[i - 1]) && line[i] == ','
				&& ftc_is_num(line[i + 1])) || ftc_is_num(line[i])))
	{
		if (index > 2)
			return (FALSE);
		if (line[i] == ',')
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
	const char	**paths = {"NO ", "SO ", "WE ", "EA ", NULL};
	const char	**colors = {"F ", "C ", NULL};

	if (ftc_starts_with_any(line->text, paths))
		return (is_path(line->text + 3));
	if (ftc_starts_with_any(line->text, colors))
		return (is_color(line->text + 2));
	return (line->len == 0);
}

BOOL	is_map_char(char c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

t_map	*import_map_from_file(char *file_name)
{
	t_map		*new_map;
	t_ft_string	*line;
	BOOL		map_mode;
	int			i;
	int			j;

	new_map = ft_malloc(sizeof(t_map));
	new_map->lines = ft_file_to_list(file_name);
	map_mode = FALSE;
	i = 0;
	while (i < new_map->lines->len)
	{
		line = ft_list_item_at(new_map->lines, i);
		if (map_mode == FALSE && is_info(line) == FALSE)
			map_mode = TRUE;
		if (!map_mode)
			;//load data from line into data struct
		else
		{
			j = 0;
			while (line->text[j])
				if (is_map_char(line->text[j++]) == FALSE)
					;//incorrect map, deal with
		}
		i++;
	}
	// ft_list_add_front(new_map->lines, line);
	return (new_map);
}

char	map_get_at(t_map *map, UINT x, UINT y)
{
	t_ft_string	*line;

	if (y >= map->lines->len)
		return ('\0');
	line = ft_list_item_at(map->lines, y);
	if (x >= line->len)
		return ('\0');
	return (line->text[x]);
}
