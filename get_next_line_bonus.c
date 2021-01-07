/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:05:02 by llescure          #+#    #+#             */
/*   Updated: 2021/01/07 18:05:25 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*allocate_static(void)
{
	char	*temp;

	if (!(temp = malloc(sizeof(char))))
		return (NULL);
	temp[0] = '\0';
	return (temp);
}

int		return_value(int char_read)
{
	if (char_read < 0)
		return (-1);
	if (char_read == 0)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char				buf[BUF + 1];
	static char			*temp[4096];
	int					char_read;
	char				*cpy;

	char_read = 1;
	if (fd < 0 || BUF <= 0 || line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	if (temp[fd] == NULL)
		if (!(temp[fd] = allocate_static()))
			return (-1);
	while ((ft_strchr(temp[fd], '\n') == NULL) &&
			(char_read = read(fd, buf, BUF)) > 0)
	{
		buf[char_read] = '\0';
		cpy = temp[fd];
		temp[fd] = ft_strjoin(cpy, buf);
		free(cpy);
	}
	*line = ft_trim(temp[fd], '\n');
	cpy = temp[fd];
	temp[fd] = get_temp(temp[fd], '\n');
	free(cpy);
	return (return_value(char_read));
}
