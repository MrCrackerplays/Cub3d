/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   next_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:04:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:14:20 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <ft_file.h>
#include <ft_string.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>

#include "read_block.h"

static void	static_get_next_block(t_read_block *block, int fd)
{
	block->buff[0] = '\0';
	block->start = 0;
	block->index = 0;
	block->ret = read(fd, block->buff, READ_BUFFER_SIZE);
	if (block->ret == -1)
	{
		block->buff[0] = '\0';
		block->is_end = TRUE;
		return ;
	}
	block->buff[block->ret] = '\0';
	block->is_end = block->ret < READ_BUFFER_SIZE;
}

static t_ft_string	*static_parser(t_read_block *block, int fd,
		t_ft_string *line)
{
	t_ft_string	*tmp_string;

	while (1)
	{
		while (block->buff[block->index] && block->buff[block->index] != '\n')
			block->index++;
		if (block->buff[block->index] == '\n')
			block->index++;
		tmp_string = _ft_string_new(block->buff + block->start,
				block->index - block->start);
		ft_string_cat_to(line, tmp_string);
		ft_string_free(tmp_string);
		block->start = block->index;
		if (block->is_end || block->buff[block->index - 1] == '\n')
			return (line);
		static_get_next_block(block, fd);
	}
}

t_ft_string	*ft_file_next_line(int fd)
{
	static t_read_block	block;

	if (fd < 0 || READ_BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		ft_exit_error_d("libft: ft_file_next_line: invalid file descriptor");
	if (!block.buff[block.index] || block.fd != fd)
	{
		block.fd = fd;
		static_get_next_block(&block, fd);
	}
	if (block.is_end && block.buff[block.index] == '\0')
		return (NULL);
	return (static_parser(&block, fd, _ft_string_new("", 0)));
}
