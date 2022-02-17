/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 18:07:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/17 13:48:37 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_print.h>

#ifndef DEBUG
# define DEBUG 0
#endif

int	ft_exit_error(char *error)
{
	ft_print(2, "Error\n%s\n", error);
	exit(1);
	return (0);
}

int	ft_exit_error_n(char *error, int error_no)
{
	ft_print(2, "Error\n%s\n", error);
	exit(error_no);
	return (0);
}

int	ft_exit_error_d(char *error)
{
	if (DEBUG)
		ft_print(2, "Error\n%s\n", error);
	exit(1);
	return (0);
}

int	ft_exit_error_dn(char *error, int error_no)
{
	if (DEBUG)
		ft_print(2, "Error\n%s\n", error);
	exit(error_no);
	return (0);
}
