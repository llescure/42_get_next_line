/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:49:03 by llescure          #+#    #+#             */
/*   Updated: 2020/11/18 22:29:11 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *temp = "";
	char *cpy;
	int	char_read;
	
	cpy = "";
	char_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while ((char_read = read(fd, buf, BUFFER_SIZE)) > 0 && ft_strchr(buf, '\n') == NULL)
	{
		buf[char_read] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	printf("char%i\n", char_read);
	if (char_read == 0)
		return (0);
	if (char_read != 0)
	{
		buf[char_read] = '\0';
		temp = ft_strjoin(temp, buf);
		cpy = ft_trim(temp, '\n');
		*line = ft_strjoin(*line, cpy);
		temp = ft_strchr(temp, '\n');
		return (1);
	}
	return (-1);
}	

int		main(void)
{
	int fd;
	int rslt;
	char *str;

	if(!(str = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);
	fd = open("test.txt", O_RDWR);
	while ((rslt = get_next_line(fd, &str)) != 0)
	{
		printf("str%s\n", str);
		printf("%i\n", rslt);
	}
		printf("%i\n", rslt);
}
