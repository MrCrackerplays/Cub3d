/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rw.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 16:49:56 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:24:45 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <ft_file.h>
#include <ft_string.h>
#include <ft_print.h>

t_ft_string	*ft_file_read(char *name)
{
	t_ft_string	*file;
	int			fd;

	fd = ft_file_open(name, O_RDONLY);
	file = ft_file_read_fd(fd);
	close(fd);
	return (file);
}

void	ft_file_write(char *name, char *text)
{
	int	fd;

	fd = ft_file_open(name, O_WRONLY | O_CREAT | O_TRUNC);
	_ft_print_s(fd, text);
	close(fd);
}

void	ft_file_write_m(char *name, t_ft_string *str)
{
	int	fd;

	fd = ft_file_open(name, O_WRONLY | O_CREAT | O_TRUNC);
	_ft_print_m(fd, str);
	close(fd);
}

void	ft_file_add(char *name, char *text)
{
	int	fd;

	fd = ft_file_open(name, O_WRONLY | O_CREAT | O_APPEND);
	_ft_print_s(fd, text);
	close(fd);
}

void	ft_file_add_m(char *name, t_ft_string *str)
{
	int	fd;

	fd = ft_file_open(name, O_WRONLY | O_CREAT | O_APPEND);
	_ft_print_m(fd, str);
	close(fd);
}
