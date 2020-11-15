/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:49:03 by llescure          #+#    #+#             */
/*   Updated: 2020/11/15 22:35:22 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char *buf;
	static char *temp;
	int compt;
	
	temp = NULL;
	if(!(buf = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	compt = 0;
	if (ft_strchr(temp, '\n') != NULL)
	{
		*(line + compt) = ft_trim(temp, '\n');
		compt++;
		temp = ft_strchr(temp, '\n');
		return (1);
	}
	else if (ft_strchr(temp, '\0') != NULL)
	{
		*(line + compt) = ft_trim(buf, '\0');
		free(temp);
		return (0);
	}
	while (read(fd, buf, BUFFER_SIZE) >= 0 && ft_strchr(buf, '\n') == NULL)
	{
		printf("%s", ft_strjoin(temp, buf));
		*(line + compt) = ft_trim(buf, '\n');
		temp = ft_strchr(buf, '\n');
		compt++;
		free(buf);
	}
	return (-1);
}	

int		main(void)
{
	int fd;
	char *str;

	if(!(str = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);
	fd = open("test.txt", O_RDWR);
	printf("%i\n", get_next_line(fd, &str));
}
