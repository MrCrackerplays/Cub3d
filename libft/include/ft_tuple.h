/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tuple.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:59:37 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 14:14:24 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TUPLE_H
# define FT_TUPLE_H

typedef struct s_tuple
{
	void	*item1;
	void	*item2;
}	t_tuple;

typedef struct s_tuple3
{
	void	*item1;
	void	*item2;
	void	*item3;
}	t_tuple3;

typedef struct s_tuple4
{
	void	*item1;
	void	*item2;
	void	*item3;
	void	*item4;
}	t_tuple4;

#endif
