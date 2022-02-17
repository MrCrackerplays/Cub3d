/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit_error.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 17:10:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:18:14 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_ERROR_H
# define FT_EXIT_ERROR_H

int	ft_exit_error(char *error);
int	ft_exit_error_n(char *error, int error_no);
int	ft_exit_error_d(char *error);
int	ft_exit_error_dn(char *error, int error_no);

#endif
