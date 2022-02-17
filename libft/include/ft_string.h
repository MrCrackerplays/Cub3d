/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 17:19:55 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/11 14:25:01 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdarg.h>
# include <ft_cstring.h>
# include <ft_int_types.h>
# include <ft_list.h>

typedef struct s_ft_string{
	char	*text;
	UINT	len;
}	t_ft_string;

t_ft_string	*ft_string_new(char *src);
t_ft_string	*_ft_string_new(char *src, UINT length);
void		ft_string_free(t_ft_string *string);

t_ft_string	*ft_string_new_f(char *format, ...);
t_ft_string	*_ft_string_new_f_parser(char *format, va_list list);
t_ft_string	*_ft_string_new_f(char *format, void **args);
t_ft_string	*ft_string_new_i(LLONG n);
t_ft_string	*ft_string_new_u(ULLONG n);
t_ft_string	*ft_string_new_x(ULLONG n);

t_ft_string	*ft_string_copy_to(t_ft_string *des, t_ft_string *src);
t_ft_string	*ft_string_copy_to_s(t_ft_string *des, char *src);

t_ft_string	*ft_string_cat_to(t_ft_string *des, t_ft_string *src);
t_ft_string	*ft_string_cat_to_s(t_ft_string *des, char *src);
t_ft_string	*ft_string_cat_to_c(t_ft_string *des, char c);

t_ft_string	*ft_string_insert(t_ft_string *des, UINT index, t_ft_string *src);
t_ft_string	*ft_string_insert_s(t_ft_string *des, UINT index, char *src);

t_ft_string	*ft_string_cut(t_ft_string *des, UINT start, UINT length);
t_ft_string	*ft_string_cutout(t_ft_string *des, UINT start, UINT length);

t_ft_list	*ft_string_split_to_list(char *string, char c);
t_ft_list	*ft_string_split_to_list_clean(char *string, char c);
char		**ft_string_split_to_array(char *string, char c);
char		**ft_string_split_to_array_clean(char *string, char c);

char		*ft_string_strip(t_ft_string *string);
UINT		ft_string_strip_l(t_ft_string *string);

#endif
