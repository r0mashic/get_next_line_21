/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balysane <balysane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:25:14 by balysane          #+#    #+#             */
/*   Updated: 2022/01/10 14:15:38 by balysane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	static int	i;
	char		*line1;
	char		*line2;

	if (buff[i] == '\0')
		if (!ft_read(fd, buff, &i))
			return (0);
	line1 = ft_write(buff, &i);
	while (check_next_line(line1) == 0)
	{
		if (!ft_read(fd, buff, &i))
			return (line1);
		line2 = ft_write(buff, &i);
		if (!line2)
		{
			free(line1);
			return (line2);
		}
		line1 = ft_strjoin(line1, line2);
	}
	return (line1);
}
