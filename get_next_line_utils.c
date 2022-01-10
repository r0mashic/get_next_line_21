/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balysane <balysane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:25:14 by balysane          #+#    #+#             */
/*   Updated: 2022/01/10 14:29:02 by balysane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if ((!s1) || (!s2))
		return (0);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	free(s2);
	return (str);
}

int	check_next_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = -1;
	while (line[++i])
		if (line[i] == '\n')
			return (1);
	return (0);
}

int	ft_read(int fd, char *buff, int *i)
{
	int	index;

	index = read(fd, buff, BUFFER_SIZE);
	if (index <= 0)
		return (0);
	*i = 0;
	buff[index] = '\0';
	return (index);
}

char	*ft_write(const char *buff, int *i)
{
	int		j;
	char	*line2;

	j = *i;
	while (buff[j] != '\0')
		j++;
	line2 = (char *)malloc(j - *i + 1);
	if (!line2)
		return (0);
	j = 0;
	while (buff[*i] != '\0' && buff[*i] != '\n')
		line2[j++] = buff[(*i)++];
	if (buff[*i] == '\n')
	{
		line2[j++] = '\n';
		(*i)++;
	}
	line2[j] = '\0';
	return (line2);
}
