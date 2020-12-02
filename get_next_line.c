/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:49:03 by llescure          #+#    #+#             */
/*   Updated: 2020/12/02 21:51:32 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char					buf[BUF + 1];
  static char				*temp = "";
	int						char_read;

	char_read = 0;
	if (fd < 0 || BUF <= 0 || line == NULL)
		return (-1);
	while ((ft_strchr(temp, '\n') == NULL) && (char_read = read(fd, buf, BUF)) > 0)
	{
		buf[char_read] = '\0';
		temp = ft_strjoin(temp, buf);
	}
  //printf("temp%s\n", temp);
  *line = ft_trim(temp, '\n');
  temp = get_temp(temp, '\n');
	if (char_read < 0)
		return (-1);
  if (temp == NULL)
    return (0);
  return (1);
}
