/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp_open.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 15:28:09 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:27:23 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <ft_string.h>
#include <ft_exit_error.h>

int	ft_tmp_open(char *name, int mode)
{
	t_ft_string	*tmp;
	int			out;

	if (!name)
		ft_exit_error_d("libft: ft_file_open: got a NULL cstring");
	tmp = ft_string_new(getenv("TMPDIR"));
	if (!tmp)
		ft_exit_error_d("libft: ft_tmp_open: TMPDIR not set in env");
	ft_string_cat_to_s(tmp, name);
	out = open(tmp->text, mode, 0777);
	ft_string_free(tmp);
	return (out);
}
