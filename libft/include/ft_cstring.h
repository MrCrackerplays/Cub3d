/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cstring.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 18:31:40 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 18:23:44 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CSTRING_H
# define FT_CSTRING_H

# include <stddef.h>
# include <ft_int_types.h>

int		ft_strlen(char *src);

char	*ft_strdup(char *src);

char	*ft_strcat(char *des, char *src);
char	*ft_strcpy(char *des, char *src);
char	*ft_strncpy(char *des, const char *src, size_t n);

int		ft_strcmp(char *src1, char *src2);

LLONG	ft_atoi(char *src);
ULLONG	ft_atou(char *src);

#endif
