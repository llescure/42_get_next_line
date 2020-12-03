/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:59:38 by llescure          #+#    #+#             */
/*   Updated: 2020/12/02 23:14:54 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int		main(void)
{
 	int		fd;
 	int		rslt;
 	char	*str;
 
 	if (!(str = malloc(sizeof(char) * BUF)))
 		return (0);
 	fd = open("test.txt", O_RDWR);
 	while ((rslt = get_next_line(fd, &str)) != 0)
 	{
 		printf("str%s\n", str);
 		printf("%i\n", rslt);
 	}
 	printf("%i\n", rslt);
}
*/
// s'occuper des leaks
#include <stdio.h>
#include <unistd.h>

int main() 
{
	int res;
	char *line;

	int fd[2];

	pipe(fd);

	char *text = "hello\nhello\nhellohello\nhello";
	write(fd[1], text, ft_strlen(text));
	close(fd[1]);

	while ((res = get_next_line(fd[0], &line)) != 0)
	{
		printf("%d: %s\n", res ,line);
	}
  free(line);
}
