/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cstring.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 18:31:40 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/24 16:26:52 by rdrazsky      ########   odam.nl         */
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

char	*ft_strstr(char *big, char *little);
char	*ft_strnstr(char *big, char *little, size_t len);

int		ft_strcmp(char *src1, char *src2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

LLONG	ft_atoi(char *src);
ULLONG	ft_atou(char *src);

#endif
