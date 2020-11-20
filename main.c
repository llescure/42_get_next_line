/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:59:38 by llescure          #+#    #+#             */
/*   Updated: 2020/11/20 15:40:09 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
