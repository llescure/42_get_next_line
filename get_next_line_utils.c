/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:09:43 by llescure          #+#    #+#             */
/*   Updated: 2020/11/17 22:36:32 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *str, int c)
{
	unsigned long i;

	i = 0;
	if (c == '\0' && str[0] == '\0')
		return ((char *)str);
	while (i <= ft_strlen(str))
	{
		if (c == str[i])
			return ((char *)&str[i + 1]);
		i++;
	}
	return (0);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int						i;
	unsigned int						j;
	char								*rslt;

	if (!(rslt = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		rslt[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		rslt[i] = s2[j];
		i++;
		j++;
	}
	rslt[i] = '\0';
	return (rslt);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}

char			*ft_trim(char *str, int c)
{	
	size_t i;
	char *new;

	i = 0;
	if(!(new = malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (c == str[i])
		{
			ft_strlcpy(new, (const char *)str, i + 1);
			return (new);
		}
		i++;
	}
	return (NULL);
}	
