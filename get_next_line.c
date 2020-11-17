/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:49:03 by llescure          #+#    #+#             */
/*   Updated: 2020/11/17 23:24:06 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *temp = "";
	char *cpy;
	int	cara_read;
	
	cpy = "";
	cara_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while ((cara_read = read(fd, buf, BUFFER_SIZE)) > 0 && ft_strchr(buf, '\n') == NULL)
	{
		buf[cara_read] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	buf[cara_read] = '\0';
	temp = ft_strjoin(temp, buf);
	cpy = ft_trim(temp, '\n');
	*line = ft_strjoin(*line, cpy);
	temp = ft_strchr(temp, '\n');
	while (ft_strchr(temp, '\n') != NULL)
	{
		cpy = ft_trim(temp, '\n');
		*line = ft_strjoin(*line, cpy);
		temp = ft_strchr(temp, '\n');
	}
	printf("line2%s\n", *line);
	printf("temp2%s\n", temp);
	if (ft_strlen(temp) == 0)
		return (0);
	return (1);
}	

int		main(void)
{
	int fd;
	char *str;

	if(!(str = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);
	fd = open("test.txt", O_RDWR);
	while (get_next_line(fd, &str) != 0)
		printf("%i\n", get_next_line(fd, &str));
}
