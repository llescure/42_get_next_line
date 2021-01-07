/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:07:27 by llescure          #+#    #+#             */
/*   Updated: 2021/01/07 18:07:38 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define BUF BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*allocate_static(void);
int			return_value(int char_read);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
char		*ft_trim(char *str, int c);
char		*get_temp(char *str, int c);

#endif
