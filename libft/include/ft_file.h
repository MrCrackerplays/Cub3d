/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:04:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 19:17:07 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include <fcntl.h>
# include <ft_int_types.h>
# include <ft_string.h>
# include <ft_list.h>

t_ft_string		*ft_file_next_line(int fd);
t_ft_string		*ft_file_read_fd(int fd);

int				ft_file_open(char *file_name, int mode);
t_ft_string		*ft_file_read(char *file_name);
void			ft_file_write(char *file_name, char *text);
void			ft_file_write_m(char *file_name, t_ft_string *str);
void			ft_file_add(char *file_name, char *text);
void			ft_file_add_m(char *file_name, t_ft_string *str);

int				ft_tmp_open(char *file_name, int mode);
t_ft_string		*ft_tmp_read(char *file_name);
void			ft_tmp_write(char *file_name, char *text);
void			ft_tmp_write_m(char *file_name, t_ft_string *str);
void			ft_tmp_add(char *file_name, char *text);
void			ft_tmp_add_m(char *file_name, t_ft_string *str);

t_ft_list		*ft_file_to_list(char *file_name);

#endif
