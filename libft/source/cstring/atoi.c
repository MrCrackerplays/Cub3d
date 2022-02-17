/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 19:54:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 18:31:47 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_types.h>
#include <ft_exit_error.h>

LLONG	ft_atoi(char *src)
{
	LLONG	num;
	LLONG	mul;

	if (!src)
		ft_exit_error_d("libft: ft_atoi: got a NULL cstring");
	num = 0;
	mul = 1;
	while ((*src >= 9 && *src <= 13) || *src == ' ')
		src++;
	if (*src == '+')
		src++;
	else if (*src == '-')
	{
		mul = -1;
		src++;
	}
	while (*src >= '0' && *src <= '9')
	{
		num *= 10;
		num += *src - '0';
		src++;
	}
	return (num * mul);
}

ULLONG	ft_atou(char *src)
{
	ULLONG	num;

	if (!src)
		ft_exit_error_d("libft: ft_atou: got a NULL cstring");
	num = 0;
	while ((*src >= 9 && *src <= 13) || *src == ' ')
		src++;
	if (*src == '+')
		src++;
	while (*src >= '0' && *src <= '9')
	{
		num *= 10;
		num += *src - '0';
		src++;
	}
	return (num);
}
