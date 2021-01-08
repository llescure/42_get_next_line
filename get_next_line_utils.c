/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:09:43 by llescure          #+#    #+#             */
/*   Updated: 2021/01/08 22:21:33 by llescure         ###   ########.fr       */
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
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char		*ft_strjoin(char *s1, char *s2)
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

char		*ft_trim(char *str, int c)
{
	char					*new_str;
	unsigned int			i;
	unsigned int			size;

	size = 0;
	while (str[size] != '\0' && str[size] != c)
		size++;
	if (!(new_str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char		*get_temp(char *str, int c)
{
	unsigned int	i;
	unsigned int	j;
	char			*temp;

	i = 0;
	j = 0;
	if (!(temp = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (temp);
	i++;
	while (str[i] != '\0')
	{
		temp[j] = str[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}
