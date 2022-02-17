/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 16:12:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:27:18 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ft_exit_error.h>

int	ft_file_open(char *name, int mode)
{
	int			out;

	if (!name)
		ft_exit_error_d("libft: ft_file_open: got a NULL cstring");
	out = open(name, mode, 0777);
	if (out < 0)
	{
		perror("libft: ft_file_open");
		exit(1);
	}
	return (out);
}
