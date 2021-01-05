/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:46:38 by llescure          #+#    #+#             */
/*   Updated: 2021/01/05 12:22:49 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define BUF BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
char		*ft_trim(char *str, int c);
char		*get_temp(char *str, int c);

#endif
