/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:46:38 by llescure          #+#    #+#             */
/*   Updated: 2021/01/09 14:35:14 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_SIZE
#  define FD_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			return_value(int char_read, char **temp);
int			error_case(int fd, char **line, char **temp, char **buf);
char		*copy_to_join(char *temp, char *buf);
char		*copy_to_get_temp(char *temp);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
char		*ft_trim(char *str, int c);
char		*get_temp(char *str, int c);

#endif
