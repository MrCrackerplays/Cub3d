/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_fd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 15:56:51 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:16:58 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_int_types.h>
#include <ft_string.h>
#include <ft_exit_error.h>

#include "read_block.h"

static void	static_get_next_block(t_read_block *block, int fd)
{
	block->buff[0] = '\0';
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

static t_ft_string	*static_parser(t_read_block *block, int fd)
{
	t_ft_string	*line;

	line = _ft_string_new("", 0);
	static_get_next_block(block, fd);
	while (1)
	{
		ft_string_cat_to_s(line, block->buff);
		if (block->is_end)
			return (line);
		static_get_next_block(block, fd);
	}
}

t_ft_string	*ft_file_read_fd(int fd)
{
	t_read_block	block;

	if (fd < 0)
		ft_exit_error_d("libft: ft_file_read_fd: invalid file descriptor");
	if (fd < 0 || READ_BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	return (static_parser(&block, fd));
}
