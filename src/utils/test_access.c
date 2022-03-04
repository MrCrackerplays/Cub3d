/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_access.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 15:35:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/03 16:10:07 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	test_access(char *file_path, char *message)
{
	const int	fd = open(file_path, O_RDONLY);

	close(fd);
	if (fd < 0)
		ft_exit_error(message);
}
