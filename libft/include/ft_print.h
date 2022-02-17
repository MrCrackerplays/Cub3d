/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:05:30 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 11:45:28 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <ft_int_types.h>
# include <ft_string.h>

/* Character */
UINT	_ft_print_c(int fd, char c);
UINT	_ft_print_c_n(int fd, char c);

/* String */
UINT	_ft_print_s(int fd, char *s);
UINT	_ft_print_s_n(int fd, char *s);

/* String */
UINT	_ft_print_m(int fd, t_ft_string *s);
UINT	_ft_print_m_n(int fd, t_ft_string *s);

/* String with unprintables */
/* This function is slow and meant for debugging only */
UINT	_ft_print_a(int fd, char *s);
UINT	_ft_print_a_n(int fd, char *s);

/* Integers */
UINT	_ft_print_i(int fd, LLONG n);
UINT	_ft_print_i_n(int fd, LLONG n);

/* Unsigned Integers */
UINT	_ft_print_u(int fd, ULLONG n);
UINT	_ft_print_u_n(int fd, ULLONG n);

/* Unsigned Hexadecimal */
UINT	_ft_print_x(int fd, ULLONG n);
UINT	_ft_print_x_n(int fd, ULLONG n);

/* New Line */
UINT	_ft_print_nl(int fd);
UINT	_ft_print_nl_c(int fd, UINT n);

/* My version of printf */
UINT	ft_print(int fd, char *format, ...);
UINT	_ft_print(int fd, char *format, void **args);

#endif
