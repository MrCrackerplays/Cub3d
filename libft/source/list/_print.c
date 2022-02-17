/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _list_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 16:41:25 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 11:44:08 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_list.h>
#include <ft_print.h>
#include <ft_int_types.h>
#include <ft_string.h>

UINT	_ft_list_print_s(int fd, t_ft_list *list)
{
	t_ft_list_node	*parse_node;
	UINT			len;

	if (!list)
		return (_ft_print_s(fd, NULL));
	len = _ft_print_c(1, '{');
	parse_node = list->first;
	while (parse_node)
	{
		len += _ft_print_s(fd, (char *)parse_node->item);
		if (parse_node->next)
			len += _ft_print_c(1, ',');
		parse_node = parse_node->next;
	}
	len += _ft_print_c(1, '}');
	return (len);
}

UINT	_ft_list_print_m(int fd, t_ft_list *list)
{
	t_ft_list_node	*parse_node;
	UINT			len;

	if (!list)
		return (_ft_print_s(fd, NULL));
	len = _ft_print_c(1, '{');
	if (list->first)
	{
		parse_node = list->first;
		while (parse_node)
		{
			len += _ft_print_m(fd, (t_ft_string *)parse_node->item);
			if (parse_node->next)
				len += _ft_print_c(1, ',');
			parse_node = parse_node->next;
		}
	}
	len += _ft_print_c(1, '}');
	return (len);
}

UINT	_ft_list_print_i(int fd, t_ft_list *list)
{
	t_ft_list_node	*parse_node;
	UINT			len;

	if (!list)
		return (_ft_print_s(fd, NULL));
	len = _ft_print_c(1, '{');
	if (list->first)
	{
		parse_node = list->first;
		while (parse_node)
		{
			len += _ft_print_i(fd, (LLONG)parse_node->item);
			if (parse_node->next)
				len += _ft_print_c(1, ',');
			parse_node = parse_node->next;
		}
	}
	len += _ft_print_c(1, '}');
	return (len);
}

UINT	_ft_list_print_u(int fd, t_ft_list *list)
{
	t_ft_list_node	*parse_node;
	UINT			len;

	if (!list)
		return (_ft_print_s(fd, NULL));
	len = _ft_print_c(1, '{');
	if (list->first)
	{
		parse_node = list->first;
		while (parse_node)
		{
			len += _ft_print_u(fd, (ULLONG)parse_node->item);
			if (parse_node->next)
				len += _ft_print_c(1, ',');
			parse_node = parse_node->next;
		}
	}
	len += _ft_print_c(1, '}');
	return (len);
}
