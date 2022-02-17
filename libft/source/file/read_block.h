/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_block.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 16:03:41 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 13:58:12 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_BLOCK_H
# define READ_BLOCK_H

# include <ft_int_types.h>

# ifndef READ_BUFFER_SIZE
// #  define READ_BUFFER_SIZE 1
// #  define READ_BUFFER_SIZE 1024
// #  define READ_BUFFER_SIZE 10240
// #  define READ_BUFFER_SIZE 20480
#  define READ_BUFFER_SIZE 512000
# endif

typedef struct s_read_block {
	char	buff[READ_BUFFER_SIZE + 1];
	BOOL	is_end;
	int		fd;
	int		ret;
	UINT	start;
	UINT	index;
}	t_read_block;

#endif
