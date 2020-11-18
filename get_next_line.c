/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:49:03 by llescure          #+#    #+#             */
/*   Updated: 2020/11/18 23:13:23 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char					buf[BUF + 1];
	static char				*temp = "";
	char					*cpy;
	int						char_read;

	cpy = "";
	char_read = 0;
	if (fd < 0 || BUF <= 0 || line == NULL)
		return (-1);
	while ((char_read = read(fd, buf, BUF)) > 0 && ft_strchr(buf, '\n') == NULL)
	{
		buf[char_read] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	buf[char_read] = '\0';
	temp = ft_strjoin(temp, buf);
	if (ft_strlen(temp) == 0)
		return (0);
	else
	{
		cpy = ft_trim(temp, '\n');
		*line = ft_strjoin(*line, cpy);
		temp = ft_strchr(temp, '\n');
		return (1);
	}
}
