/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:49:03 by llescure          #+#    #+#             */
/*   Updated: 2021/01/08 15:51:22 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*allocate_static(void)
{
	char	*temp;

	if (!(temp = malloc(sizeof(char))))
		return (NULL);
	temp[0] = '\0';
	return (temp);
}

int		return_value(int char_read, char **temp)
{
	if (char_read < 0)
		return (-1);
	if (char_read > 0)
		return (1);
	free(*temp);
	*temp = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char				*buf;
	static char			*temp = NULL;
	int					char_read;
	char				*cpy;

	char_read = 1;
	if (fd < 0 || BUF <= 0 || line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	if (temp == NULL)
		if (!(temp = allocate_static()))
			return (-1);
	if(!(buf = malloc(sizeof(char) * BUF + 1)))
		return (-1);
	while ((ft_strchr(temp, '\n') == NULL) &&
			(char_read = read(fd, buf, BUF)) > 0)
	{
		buf[char_read] = '\0';
		cpy = temp;
		temp = ft_strjoin(cpy, buf);
		free(cpy);
	}
	free(buf);
	*line = ft_trim(temp, '\n');
	cpy = temp;
	temp = get_temp(temp, '\n');
	free(cpy);
	return (return_value(char_read, &temp));
}
