/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp_rw.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 15:08:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 16:58:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <ft_file.h>
#include <ft_string.h>
#include <ft_print.h>

t_ft_string	*ft_tmmp_read(char *name)
{
	t_ft_string	*file;
	int			fd;

	fd = ft_tmp_open(name, O_RDONLY);
	file = ft_file_read_fd(fd);
	close(fd);
	return (file);
}

void	ft_tmp_write(char *name, char *text)
{
	int	fd;

	fd = ft_tmp_open(name, O_WRONLY | O_CREAT | O_TRUNC);
	_ft_print_s(fd, text);
	close(fd);
}

void	ft_tmp_write_m(char *name, t_ft_string *str)
{
	int	fd;

	fd = ft_tmp_open(name, O_WRONLY | O_CREAT | O_TRUNC);
	_ft_print_m(fd, str);
	close(fd);
}

void	ft_tmp_add(char *name, char *text)
{
	int	fd;

	fd = ft_tmp_open(name, O_WRONLY | O_CREAT | O_APPEND);
	_ft_print_s(fd, text);
	close(fd);
}

void	ft_tmp_add_ms(char *name, t_ft_string *str)
{
	int	fd;

	fd = ft_tmp_open(name, O_WRONLY | O_CREAT | O_APPEND);
	_ft_print_m(fd, str);
	close(fd);
}
