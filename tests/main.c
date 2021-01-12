/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:59:38 by llescure          #+#    #+#             */
/*   Updated: 2021/01/09 14:58:48 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
# include <fcntl.h>

int		main(void)
{
 	int		fd;
 	int		rslt;
 	char	*str;
	int compteur;

 	compteur = 0;
 	if (!(str = malloc(sizeof(char) * BUFFER_SIZE)))
 		return (0);
 	fd = open("test.txt", O_RDWR);
 	if ((rslt = get_next_line(fd, &str)) == 1)
 	{
		compteur++;
		printf("%d: %s\n", rslt, str);
 	}
 	fd = open("test2.txt", O_RDWR);
 	if ((rslt = get_next_line(fd, &str)) == 1)
 	{
		compteur++;
		printf("%d: %s\n", rslt, str);
 	}
 	printf("compteur%i\n", compteur);
}

/*int main() 
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
}*/
